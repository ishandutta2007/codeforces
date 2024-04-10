#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int maxn=300005;

//i_am_noob
//#define wiwihorz  
int n,m,a,b,par[maxn],dep[maxn],low[maxn];
vector<vector<pii>> adj(maxn),adj2(maxn);
bool vis[maxn],de[maxn],vis2[maxn];

void dfs(int u, int fa){
    par[u]=fa;
    dep[u]=fa==-1?0:dep[fa]+1;
    low[u]=dep[u];
    vis[u]=1;
    bool flag=0;
    for(auto [v,w]: adj[u]){
        if(v==fa&&!flag){
            de[u]=w;
            flag=1;
            continue;
        }
        if(vis[v]) chkmin(low[u],dep[v]);
        else dfs(v,u),chkmin(low[u],low[v]),adj2[u].pb({v,w});
    }
}

void dfs2(int u){
    vis2[u]=1;
    for(auto [v,w]: adj[u]) if(dep[v]<dep[u]&&w){
        print("YES");
        exit(0);
    }
    for(auto [v,w]: adj2[u]) if(low[v]<dep[v]) dfs2(v);
}

void orzck(){
    cin >> n >> m;
    rep(m){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({v,w}),adj[v].pb({u,w});
    }
    cin >> a >> b;
    a--,b--;
    dfs(a,-1);
    if(!vis[b]){
        print("NO");
        return;
    }
    vector<int> path;
    for(int i=b; i!=a; i=par[i]) path.pb(i);
    path.pb(a);
    reverse(all(path));
    for(auto i: path) if(!vis2[i]) dfs2(i);
    print("NO");
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}