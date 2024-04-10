#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=20,M=1e5+10,SQ=300,inf=1e9;
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
ll t,n,q,x[N],g[N];
vector<pll> adj[N];
vector<vector<ll>> a,b;
int main(){
    fast_io;
    cin >> t;
    memset(g,-1,sizeof g);
    while(t--){
        bool f=0;
        a.clear();
        b.clear();
        cin >> n >> q;
        for(ll i=1; i<=q; i++){
            ll k;
            cin >> k;
            vector<ll> t(k);
            for(ll j=0; j<k; j++) cin >> t[j];
            if(k<=SQ) a.pb(t);
            else b.pb(t);
        }
        for(ll i1=0; i1<b.size(); i1++){
            auto t=b[i1];
            fill(x,x+n+1,-1);
            for(ll i=0; i<t.size(); i++){
                x[t[i]]=i;
            }
            for(ll i2=i1+1; i2<b.size(); i2++){
                auto y=b[i2];
                ll mx=-2;
                for(ll i=y.size()-1; i>=0; i--){
                    if(x[y[i]]!=-1 && x[y[i]]<mx && y[i+1]!=t[x[y[i]]+1]) f=1;
                    mx=max(mx,x[y[i]]);
                }
            }
            for(auto y : a){
                ll mx=-2;
                for(ll i=y.size()-1; i>=0; i--){
                    if(x[y[i]]!=-1 && x[y[i]]<mx && y[i+1]!=t[x[y[i]]+1]) f=1;
                    mx=max(mx,x[y[i]]);
                }
            }
        }
        for(auto t : a){
            for(ll i=0; i<t.size(); i++){
                for(ll j=i+1; j<t.size(); j++){
                    adj[t[i]].pb({t[j],t[i+1]});
                }
            }
        }
        for(ll i=0; i<=n; i++){
            for(auto [j,k] : adj[i]){
                if(g[j]==-1) g[j]=k;
                else if(g[j]!=k) f=1;
            }
            for(auto [j,k] : adj[i]) g[j]=-1;
            adj[i].clear();
        }
        if(f) cout << "Human";
        else cout << "Robot";
        cout << '\n';
    }
    return 0;
}