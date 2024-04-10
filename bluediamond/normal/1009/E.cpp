#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD=998244353;

ll ans=0,x;
int n;

ll expow(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b%2==1) {
            ans=(ll)ans*a%MOD;
        }
        a=(ll)a*a%MOD;
        b/=2;
    }
    return ans;
}

ll f(ll x) {
    if(x==0)
        return 1;
    ll ans=(x+2)*expow(2,x-1)%MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++) {
        cin>>x;
        ans+=f(n-i-1)*x;
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/