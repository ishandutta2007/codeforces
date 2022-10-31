#include <bits/stdc++.h>
using namespace std;

long long n,l,r;
bool t;
pair<long long,long long> a[200001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        if (a[i].second==2) t=true;
    }
    if (t==false){
        cout<<"Infinity";
        return 0;
    }
    l=-20000000001;
    r=20000000001;
    while (l<r-1){
        long long mid=(l+r)/2;
        bool tt=false;
        bool ttt=false;
        long long midd=mid;
        for (int i=n;i>0;--i){
            mid-=a[i].first;
            if (a[i].second==1 && mid<1900){
                tt=true;
                break;
            } else if (a[i].second==2 && mid>=1900){
                ttt=true;
                break;
            }
        }
        if (tt==false && ttt==false) l=midd;
        else if (tt==true) l=midd;
        else r=midd;
    }
    t=false;
    long long rr=r;
    for (int i=n;i>0;--i){
    r-=a[i].first;
    if (a[i].second==1 && r<1900){
        t=true;
        break;
    } else if (a[i].second==2 && r>=1900){
        t=true;
        break;
    }
    }
    if (t==false){
        cout<<rr;
        return 0;
    }
    t=false;
    long long ll=l;
        for (int i=n;i>0;--i){
    l-=a[i].first;
    if (a[i].second==1 && l<1900){
        t=true;
        break;
    } else if (a[i].second==2 && l>=1900){
        t=true;
        break;
    }
    }
    if (t==false){
        cout<<ll;
        return 0;
    }
    cout<<"Impossible";
}