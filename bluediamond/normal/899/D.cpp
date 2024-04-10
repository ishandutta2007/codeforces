#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n;
ll cur=0;

ll cate(ll s) {
    ll ma=min(s-1,n);
    ll mi=(s+2)/2;
    if(mi<=ma) {
        return ma-mi+1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(10*cur+9<=2*n-1) {
        cur=10*cur+9;
    }
    ll add=cur+1;
    ll ans=0;
    for(ll i=1;i<=9;i++) {
        ans+=cate(cur);
        cur+=add;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/