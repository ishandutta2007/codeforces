#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=250005;

//i_am_noob
//#define wiwihorz  
int n,deg[maxn];
ll dp[maxn][2];
vector<pii> adj[maxn];
vector<ll> res,vec[maxn],nodes,ind[maxn],val[maxn];
unordered_map<int,int> rev[maxn];
bool vis[maxn];

struct BIT{
    vector<ll> val;
    void modify(int x, int y){for(int i=++x; i<sz(val); i+=i&-i) val[i]+=y;}
    ll query(int x, int y){
        ll ret=0;
        for(int i=++y; i>0; i-=i&-i) ret+=val[i];
        for(int i=x; i>0; i-=i&-i) ret-=val[i];
        return ret;
    }
};

BIT bitcnt[maxn],bit[maxn];

void dfs(int u, int par, int k){
    //bug(u,par,k);
    vis[u]=1;
    for(auto [v,w]: adj[u]){
        if(deg[v]<k) break;
        if(v!=par) dfs(v,u,k);
    }
    vector<ll> vec;
    dp[u][0]=dp[u][1]=0;
    for(auto [v,w]: adj[u]){
        if(deg[v]<k) break;
        if(v!=par) vec.pb((dp[v][0]+w)-dp[v][1]),dp[u][0]+=dp[v][1],dp[u][1]+=dp[v][1];
    }
    sort(all(vec));
    int need=deg[u]-1-k;
    if(par==-1) need++;
    if(k==2&&u==0) bug(dp[u][0]),bug(vec);
    reverse(all(vec));
    while(sz(vec)&&vec.back()<0) dp[u][0]+=vec.back(),vec.pop_back(),need--;
    reverse(all(vec));
    dp[u][1]=dp[u][0];
    ll minn,tot;
    if(k==2&&u==0){
        rep(deg[u]) bug(bit[u].query(0,i));
    }
    rep1(_,2){
        minn=inf,tot=0;
        if(need>0){
            rep1(j,sz(vec)+1){
                ll cur=0,curcnt=0;
                rep3(i,17,0){
                    if(cur+pow2(i)>=deg[u]) continue;
                    if(curcnt+bitcnt[u].val[cur+pow2(i)]+j<=need){
                        cur+=pow2(i);
                        curcnt+=bitcnt[u].val[cur];
                    }
                }
                if(k==2&&u==0) bug(cur,curcnt,j,need);
                if(curcnt+j==need) minn=min(minn,tot+bit[u].query(0,cur-1)),bug(minn);
                if(j<sz(vec)) tot+=vec[j];
            }
            dp[u][_]+=minn;
        }
        need++;
    }
    bug(k,u,dp[u][0],dp[u][1]);
}

void orzck(){
    cin >> n;
    rep(n-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({v,w}),adj[v].pb({u,w});
        deg[u]++,deg[v]++;
    }
    rep(n) sort(all(adj[i]),[](pii x, pii y){return deg[x.first]>deg[y.first];});
    rep(n) vec[deg[i]].pb(i);
    rep(n) nodes.pb(i);
    sort(all(nodes),[](int x, int y){return deg[x]>deg[y];});
    rep(n){
        bitcnt[i].val.resize(sz(adj[i])+1);
        bit[i].val.resize(sz(adj[i])+1);
        ind[i].resize(sz(adj[i]));
        rep1(j,sz(ind[i])) ind[i][j]=j;
        sort(all(ind[i]),[i](int x, int y){return adj[i][x].second<adj[i][y].second;});
        rep1(j,sz(ind[i])) rev[i][adj[i][ind[i][j]].first]=j;
        val[i].resize(sz(adj[i]));
    }
    res.resize(n);
    rep(n){
        for(auto j: nodes) vis[j]=0;
        for(auto j: nodes) if(!vis[j]) dfs(j,-1,i),res[i]+=dp[j][0],bug(i,res[i]);
        while(sz(nodes)&&deg[nodes.back()]<=i) nodes.pop_back();
        for(auto j: vec[i]) for(auto& [v,w]: adj[j]) bitcnt[v].modify(rev[v][j],1),bit[v].modify(rev[v][j],w);
    }
    for(auto i: res) print0(i);
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}