#include <bits/stdc++.h>
using namespace std;


long long a[200005];
long long b[200005];
int w,l;


inline bool f(long long mid) {
    for (int i=1;i<=w+1;++i)
        b[i]=0;
    b[1]=mid;
    int last=1;
    long long cur;
    long long z;
    for (int i=2;i<=w+1;++i) if (a[i]>0) {
        cur=a[i];
        while (last<i && b[last]==0) ++last;
        if (i-last>l) return false;
        while (last<i && cur>0) {
            while (last<i && b[last]==0) ++last;
            if (last==i) break;
            z=b[last];
            if (z>cur) z=cur;
            cur-=z;
            b[last]-=z;
            b[i]+=z;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>w>>l;
    for (int i=2;i<=w;++i)
        cin>>a[i];
    a[w+1]=1e15;
    long long ll=0;
    long long rr=1e15;
    while (ll<rr-1ll) {
        long long mid=(ll+rr)/2ll;
        if (f(mid)) ll=mid;
        else rr=mid;
    }
    if (f(rr)) ll=rr;
    cout<<ll;
}