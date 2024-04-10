#include <bits/stdc++.h>
using namespace std;


long long k,n,s,p;


inline bool f(long long mid) {
    long long kol=mid*p;
    kol/=k;
    kol*=s;
    return kol>=n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>n>>s>>p;
    long long l=1;
    long long r=1e9;
    while (l<r-1ll) {
        long long mid=(l+r)/2ll;
        if (f(mid)) r=mid;
        else l=mid;
    }
    if (f(l)) r=l;
    cout<<r;

}