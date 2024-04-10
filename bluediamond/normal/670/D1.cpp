#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
int n;
ll k;
ll need[N];
ll have[N];

inline bool ok(ll x) {
    ll cost=0;
    for(int i=1;i<=n;i++) {
        ll be=need[i]*x;
        be=max(0LL,be-have[i]);
        cost+=be;
        if(cost>k) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>need[i];
    for(int i=1;i<=n;i++) cin>>have[i];
    ll r=0,pas=(1<<30);
    while(pas) {
        if(ok(r+pas)) {
            r+=pas;
        }
        pas/=2;
    }
    cout<<r<<"\n";
    return 0;
}
/**

**/