/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QICUCODEC_P_H
#define QICUCODEC_P_H

#include "QtCore/qtextcodec.h"

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

extern "C" {
    typedef struct UConverter UConverter;
}

QT_BEGIN_NAMESPACE

#ifndef QT_NO_TEXTCODEC

class QIcuCodec : public QTextCodec
{
public:
    static QList<QByteArray> availableCodecs();
    static QList<int> availableMibs();

    static QTextCodec *defaultCodecUnlocked();

    static QTextCodec *codecForNameUnlocked(const char *name);
    static QTextCodec *codecForMibUnlocked(int mib);

    QString convertToUnicode(const char *, int, ConverterState *) const Q_DECL_OVERRIDE;
    QByteArray convertFromUnicode(const QChar *, int, ConverterState *) const Q_DECL_OVERRIDE;

    QByteArray name() const Q_DECL_OVERRIDE;
    QList<QByteArray> aliases() const Q_DECL_OVERRIDE;
    int mibEnum() const Q_DECL_OVERRIDE;

private:
    QIcuCodec(const char *name);
    ~QIcuCodec();

    UConverter *getConverter(QTextCodec::ConverterState *state) const;

    const char *m_name;
};

#endif // QT_NO_TEXTCODEC

QT_END_NAMESPACE

#endif
