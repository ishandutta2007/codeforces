#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<ld>;
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
const int N=2e2+10,LN=18,M=1e8+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
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
ll h,w,n,m,t[N][N],VC[N*N*4],dist[N*N*4],match[N*N*4],ans,mark[N*N*4],V[N][N][2];
vector<ll> G[N*N*4];
queue<ll> Q;
bool bfs(){
    memset(VC, 0, sizeof(VC));
    memset(dist, 31, sizeof(dist));
    for (int i=1; i<=n; i++) if (!match[i]){
        dist[i]=0;
        Q.push(i);
    }
    bool res=0;
    while (Q.size()){
        int v=Q.front();
        Q.pop();
        if (v<=n){
            VC[v]=1;
            for (int u:G[v]) if (dist[v]+1<dist[u]){
                dist[u]=dist[v]+1;
                Q.push(u);
            }
            continue ;
        }
        if (!match[v]){
            res=1;
            continue ;
        }
        dist[match[v]]=dist[v]+1;
        Q.push(match[v]);
    }
    return res;
}

bool dfs(int node){
    mark[node]=1;
    for (int v:G[node]) if (!match[v] || dist[node]+1==dist[v] && !mark[match[v]] && dfs(match[v])){
        match[node]=v;
        match[v]=node;
        return 1;
    }
    return 0;
}
int main(){
    fast_io;
    cin >> h >> w;
    for(ll i=1; i<=h; i++){
        for(ll j=1; j<=w; j++){
            char c;
            cin >> c;
            if(c=='#') t[i][j]=1;
            ans+=t[i][j];
            if(t[i][j] && t[i][j-1]) V[i][j][0]=++n;
            if(t[i][j] && t[i-1][j]) V[i][j][1]=++m;
        }
    }
    for(ll i=1; i<=h; i++){
        for(ll j=1; j<=w; j++){
            ll v=V[i][j][0],u=V[i][j][1]+n;
            if(v && u>n){
                G[v].pb(u);
                G[u].pb(v);
            }
            u=V[i+1][j][1]+n;
            if(v && u>n){
                G[v].pb(u);
                G[u].pb(v);
            }
            v=V[i][j+1][0];
            if(v && u>n){
                G[v].pb(u);
                G[u].pb(v);
            }
            u=V[i][j][1]+n;
            if(v && u>n){
                G[v].pb(u);
                G[u].pb(v);
            }
        }
    }
    while (bfs()){
        memset(mark, 0, sizeof(mark));
        for (int i=1; i<=n; i++) if (!match[i] && !mark[i]) ans+=dfs(i);
    }
    cout << ans-n-m;
    return 0;
}