/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!\n")
#define killmashtali kill("Hello, World!")
const int N=1e6+10,LN=19,M=3e2+10,SQ=256,/*B=737,*/inf=1e9;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t,n,m,a[N],k,A[N],B[N],C[N],D[N],H[N],d[N];
vector<pll> cp,in[N],adj[N];
vector<ll> po[N];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cp={{1,1},{n,m}};
        for(ll i=1; i<=n; i++){
            cin >> a[i];
            po[i]={};
        }
        for(ll i=1; i<=k; i++){
            cin >> A[i] >> B[i] >> C[i] >> D[i] >> H[i];
            cp.pb({A[i],B[i]});
            cp.pb({C[i],D[i]});
        }
        for(ll i=0; i<=k*2+5; i++){
            in[i]={};
            adj[i]={};
            d[i]=INF;
        }
        sort(cp.begin(),cp.end());
        cp.resize(unique(cp.begin(),cp.end())-cp.begin());
        for(ll i=1; i<=k; i++){
            ll x=lower_bound(cp.begin(),cp.end(),mp(A[i],B[i]))-cp.begin(),y=lower_bound(cp.begin(),cp.end(),mp(C[i],D[i]))-cp.begin();
            in[y].pb({x,H[i]});
        }
        for(ll i=0; i<cp.size(); i++){
            ll j=cp[i].F;
            if(!po[j].empty()){
                ll w=(cp[i].S-cp[po[j].back()].S)*a[j];
                adj[i].pb({po[j].back(),w});
                adj[po[j].back()].pb({i,w});
            }
            po[j].pb(i);
        }
        d[0]=0;
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        for(ll i=1; i<=n; i++){
            for(ll v : po[i]){
                for(auto [u,w] : in[v]){
                    if(d[u]==INF) continue;
                    d[v]=min(d[v],d[u]-w);
                }
                pq.push({d[v],v});
            }
            while(!pq.empty()){
                auto [x,v]=pq.top();
                pq.pop();
                if(d[v]!=x || x==INF) continue;
                for(auto [u,w] : adj[v]){
                    if(d[u]>d[v]+w){
                        d[u]=d[v]+w;
                        pq.push({d[u],u});
                    }
                }
            }
        }
        if(d[cp.size()-1]<INF) cout << d[cp.size()-1] << '\n';
        else cout << "NO ESCAPE\n";
    }
    return 0;
}