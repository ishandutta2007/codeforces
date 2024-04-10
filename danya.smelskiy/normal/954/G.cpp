#include <bits/stdc++.h>
using namespace std;

int n,m;
long long k;
long long a[500505];
long long q[500505];


inline bool f(long long mid) {
    long long kol=0;
    for (int i=1;i<=n;++i)
        q[i]=0;
    long long last=0;
    long long z;
    for (int i=1;i<=n;++i) {
        last+=q[i];
        if (a[i]+last>=mid) continue;
        z=mid-a[i]-last;
        kol+=z;
        if (kol>k) return false;
        if (m) {
            q[i+1]+=z;
            if (i+m+m+1<=n) q[i+m+m+1]-=z;
        }
    }
    return (kol<=k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    long long ll;
    long long rr;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        ll=i-m;
        if (ll<=0) ll=1;
        rr=i+m+1;
        if (rr>n) rr=n+1;
        q[ll]+=a[i];
        q[rr]-=a[i];
    }
    long long last=0;
    for (int i=1;i<=n;++i) {
        last+=q[i];
        a[i]=last;
    }
    long long l=0;
    long long r=2e18;
    while (l<r-1ll) {
        long long mid=(l+r)/2ll;
        if (f(mid)) l=mid;
        else r=mid;
    }
    if (f(r)) l=r;
    cout<<l;
}