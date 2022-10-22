#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=4e5+10,LN=20,SQ=550,M=1e9+10;
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
ll n,col[N],c,m;
bool r[N];
vector<ll> out[N],in[N],topol;
bool fl[N];
pll t[N];
void add_edge(ll v, ll u){
    out[v].push_back(u);
    in[u].push_back(v);
}
void dfs(ll v){
    fl[v]=1;
    for(ll u : out[v]) if(!fl[u]) dfs(u);
    topol.push_back(v);
}
void sfd(ll v){
    fl[v]=1;
    col[v]=c;
    for(ll u : in[v]) if(!fl[u]) sfd(u);
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) cin >> r[i];
    for(ll i=1; i<=m; i++){
        ll x;
        cin >> x;
        for(ll j=0; j<x; j++){
            ll y;
            cin >> y;
            if(t[y].F==0) t[y].F=i*2;
            else t[y].S=i*2;
        }
    }
    for(ll i=1; i<=n; i++){
        ll y=i;
        if(r[i]) add_edge(t[y].F^1,t[y].S^1),add_edge(t[y].F,t[y].S),add_edge(t[y].S^1,t[y].F^1),add_edge(t[y].S,t[y].F);
        else add_edge(t[y].F^1,t[y].S),add_edge(t[y].F,t[y].S^1),add_edge(t[y].S^1,t[y].F),add_edge(t[y].S,t[y].F^1);
    }
    for(ll i=1; i<=2*m+1; i++) if(!fl[i]) dfs(i);
    reverse(topol.begin(),topol.end());
    memset(fl,0,sizeof fl);
    for(ll i : topol) if(!fl[i]) sfd(i),c++;
    for(ll i=1; i<=m; i++){
        if(col[2*i]==col[2*i+1]) return cout << "NO\n", 0;
    }
    cout << "YES\n";
    return 0;
}