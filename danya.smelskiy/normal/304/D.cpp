#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,a,b,ll,rr,ll1,rr1;


int main(){
    cin>>n>>m>>x>>y>>a>>b;
    while (__gcd(a,b)>1) {
        long long xx=__gcd(a,b);
        a/=xx;
        b/=xx;
    }
    long long l=0;
    long long r=n;
    while (l<r-1) {
        long long mid=(l+r)/2;
        if (a*mid<=n && b*mid<=m) l=mid;
        else r=mid;
    }
    if (a*r<=n && b*r<=m) l=r;
    a*=l;
    b*=l;
    if (a%2==0) {
        long long xx=a/2;
        if (x-xx>=0 && x+xx<=n) { ll=x-xx; rr=x+xx;}
        else {
            if (x-xx<0) {
                ll=0;
                rr=a;
            } else {
                rr=n;
                ll=n-a;
            }
        }
    } else {
        long long xx=a/2;
        if (x-xx-1>=0 && x+xx<=n) {
            ll=x-xx-1;
            rr=ll+a;
        } else {
            if (x-xx-1<0) {
                ll=0;
                rr=a;
            } else {
                rr=n;
                ll=n-a;
            }
        }
    }
    if (b%2==0) {
        long long xx=b/2;
        if (y-xx>=0 && y+xx<=m) { ll1=y-xx; rr1=y+xx;}
        else {
            if (y-xx<0) {
                ll1=0;
                rr1=b;
            } else {
                rr1=m;
                ll1=m-b;
            }
        }
    } else {
        long long xx=b/2;
        if (y-xx-1>=0 && y+xx<=m) {
            ll1=y-xx-1;
            rr1=ll1+b;
        } else {
            if (y-xx-1<0) {
                ll1=0;
                rr1=b;
            } else {
                rr1=m;
                ll1=m-b;
            }
        }
    }
    cout<<ll<<" "<<ll1<<" "<<rr<<" "<<rr1;
}