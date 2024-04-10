#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


long long n,m,k;

inline long long pw(long long x,long long y) {
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    if (k==-1 && n%2!=m%2) {
        cout<<0;
        return 0;
    }
    long long x=n-1ll;
    long long y=m-1ll;
    long long res=pw(2,x);
    res=pw(res,y);
    cout<<res;
}