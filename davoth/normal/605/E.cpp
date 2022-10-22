#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc 1+(v<<1)
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=2e5+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m;
double e[N],t[N];
bool f[N];
vector<pair<ll,double>> adj[N];
priority_queue<pair<double,ll>> pq;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            ll p;
            cin >> p;
            if(p) adj[j].pb({i,p/100.0});
        }
    }
    cout << fixed << setprecision(7);
    pq.push({0,n});
    while(!pq.empty()){
        ll v=pq.top().S;
        pq.pop();
        if(f[v]) continue;
        f[v]=1;
        for(pair<ll,double> g : adj[v]){
            ll u=g.F;
            double p=g.S;
            if(f[u]==1) continue;
            e[u]*=t[u];
            if(e[u]==0) e[u]=1;
            e[u]+=(1-t[u])*p*(e[v]);
            t[u]+=(1-t[u])*p;
            e[u]/=t[u];
            pq.push({-e[u],u});
        }
    }
    cout << e[1] << '\n';
    return 0;
}