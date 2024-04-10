#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[100];

inline void no(){
    cout<<"ugly";
    exit(0);
}
int main(){
    for (int i=1;i<=8;++i)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+9);
    if (!(a[1].first==a[2].first && a[2].first==a[3].first)) no();
    if (!a[4].first==a[5].first) no();
    if (!(a[6].first==a[7].first && a[7].first==a[8].first)) no();
    if (!(a[1].first<a[4].first && a[4].first<a[6].first)) no();
    if (!(a[1].second==a[4].second && a[4].second==a[6].second)) no();
    if (!(a[2].second==a[7].second)) no();
    if (!(a[3].second==a[5].second && a[5].second==a[8].second)) no();
    if (!(a[1].second<a[2].second && a[2].second<a[3].second)) no();
    if (!(a[4].second<a[5].second)) no();
    if (!(a[6].second<a[7].second && a[7].second<a[8].second)) no();
    cout<<"respectable";
}