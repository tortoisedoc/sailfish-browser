/****************************************************************************
**
** Copyright (C) 2013 Jolla Ltd.
** Contact: Vesa-Matti Hartikainen <vesa-matti.hartikainen@jollamobile.com>
**
****************************************************************************/
#ifndef BROWSERSERVICE_H
#define BROWSERSERVICE_H

#include <QObject>
#include <QStringList>

class BrowserService : public QObject
{
    Q_OBJECT
public:
    BrowserService(QObject * parent);
    bool registered() const;
    QString serviceName() const;

public slots:
    void openUrl(QStringList args);
    void cancelTransfer(int transferId);
    void restartTransfer(int transferId);

signals:
    void openUrlRequested(QString url);
    void cancelTransferRequested(int transferId);
    void restartTransferRequested(int transferId);

private:
    bool m_registered;
};

#endif // BROWSERSERVICE_H