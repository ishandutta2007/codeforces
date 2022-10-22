#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e3+10,LN=20,SQ=550,M=1e9+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,c[N],dp[N][N],ps[N];
vector<ll> adj[N];
void dfs(ll v, ll p){
    if(adj[v].size()==1) c[v]=1,dp[v][1]=0;
    if(adj[v].size()>1) dp[v][0]=0;
    for(ll u : adj[v]){
        if(u!=p){
            dfs(u,v);
            for(ll i=0; i<=c[v]; i++){
                for(ll j=0; j<=c[u]; j++){
                    ps[i+j]=min({ps[i+j],dp[v][i]+dp[u][j],dp[v][i]+1+dp[u][c[u]-j]});
                }
            }
            c[v]+=c[u];
            for(ll i=0; i<=c[v]; i++) dp[v][i]=ps[i],ps[i]=INF;
        }
    }
}
int main(){
    fast_io;
    memset(dp,63,sizeof dp);
    memset(ps,63,sizeof ps);
    cin >> n;
    for(ll i=0; i<n-1; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1,0);
    cout << dp[1][c[1]>>1] << '\n';
    return 0;
}