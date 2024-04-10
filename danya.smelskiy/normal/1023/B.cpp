#include <bits/stdc++.h>
using namespace std;



long long n,m;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    long long l=1;
    long long r=n;
    long long x=m/2ll;
    if (m%2ll==0) --x;
    r=min(r,x);
    long long xx=r;
    while (l<r-1ll) {
        long long mid=(l+r)>>1;
        if (m-mid<=n) r=mid;
        else l=mid;
    }
    if (m-l<=n) r=l;
    if (m-r<=n) cout<<xx-r+1ll;
    else cout<<0;


}