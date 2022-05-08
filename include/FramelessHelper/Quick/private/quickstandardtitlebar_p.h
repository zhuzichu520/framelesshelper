/*
 * MIT License
 *
 * Copyright (C) 2022 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "framelesshelperquick_global.h"
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
#include <QtQuick/private/qquickrectangle_p.h>

QT_BEGIN_NAMESPACE
class QQuickLabel;
class QQuickRow;
QT_END_NAMESPACE

FRAMELESSHELPER_BEGIN_NAMESPACE

class QuickStandardMinimizeButton;
class QuickStandardMaximizeButton;
class QuickStandardCloseButton;

class FRAMELESSHELPER_QUICK_API QuickStandardTitleBar : public QQuickRectangle
{
    Q_OBJECT
#ifdef QML_NAMED_ELEMENT
    QML_NAMED_ELEMENT(StandardTitleBar)
#endif
    Q_DISABLE_COPY_MOVE(QuickStandardTitleBar)
    Q_PROPERTY(Qt::Alignment titleLabelAlignment READ titleLabelAlignment WRITE setTitleLabelAlignment NOTIFY titleLabelAlignmentChanged FINAL)
    Q_PROPERTY(QuickStandardMinimizeButton* minimizeButton READ minimizeButton CONSTANT FINAL)
    Q_PROPERTY(QuickStandardMaximizeButton* maximizeButton READ maximizeButton CONSTANT FINAL)
    Q_PROPERTY(QuickStandardCloseButton* closeButton READ closeButton CONSTANT FINAL)
    Q_PROPERTY(bool extended READ isExtended WRITE setExtended NOTIFY extendedChanged FINAL)

public:
    explicit QuickStandardTitleBar(QQuickItem *parent = nullptr);
    ~QuickStandardTitleBar() override;

    Q_NODISCARD Qt::Alignment titleLabelAlignment() const;
    void setTitleLabelAlignment(const Qt::Alignment value);

    Q_NODISCARD QuickStandardMinimizeButton *minimizeButton() const;
    Q_NODISCARD QuickStandardMaximizeButton *maximizeButton() const;
    Q_NODISCARD QuickStandardCloseButton *closeButton() const;

    Q_NODISCARD bool isExtended() const;
    void setExtended(const bool value);

protected:
    void itemChange(const ItemChange change, const ItemChangeData &value) override;

private Q_SLOTS:
    void updateMaximizeButton();
    void updateTitleLabelText();
    void updateTitleBarColor();
    void clickMinimizeButton();
    void clickMaximizeButton();
    void clickCloseButton();

Q_SIGNALS:
    void titleLabelAlignmentChanged();
    void extendedChanged();

private:
    void initialize();
    void updateAll();

private:
    Qt::Alignment m_labelAlignment = {};
    QScopedPointer<QQuickLabel> m_label;
    QScopedPointer<QQuickRow> m_row;
    QScopedPointer<QuickStandardMinimizeButton> m_minBtn;
    QScopedPointer<QuickStandardMaximizeButton> m_maxBtn;
    QScopedPointer<QuickStandardCloseButton> m_closeBtn;
    QMetaObject::Connection m_windowStateChangeConnection = {};
    QMetaObject::Connection m_windowActiveChangeConnection = {};
    QMetaObject::Connection m_windowTitleChangeConnection = {};
    bool m_extended = false;
};

FRAMELESSHELPER_END_NAMESPACE

QML_DECLARE_TYPE(FRAMELESSHELPER_PREPEND_NAMESPACE(QuickStandardTitleBar))
#endif // (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
