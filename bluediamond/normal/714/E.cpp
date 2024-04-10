#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=3000+5;
ll n,v[N];
set<ll>s;
ll a[N],y=0;

ll dp[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) {
        cin>>v[i];
        v[i]-=(i-1);
        s.insert(v[i]);
    }
    for(auto itr:s) {
        a[++y]=itr;
    }
    for(ll i=1;i<=y;i++) {
        dp[1][i]=abs(v[1]-a[i]);
    }
    for(ll i=2;i<=n;i++) {
        ll mi=dp[i-1][1];
        for(ll j=1;j<=y;j++) {
            mi=min(mi,dp[i-1][j]);
            dp[i][j]=mi+abs(v[i]-a[j]);
        }
    }
    ll ans=dp[n][1];
    for(ll i=1;i<=y;i++) {
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<"\n";
    return 0;
}