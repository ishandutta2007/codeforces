#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

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

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005,maxm=10000005,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,m,e[maxn][2],res[maxn],color[maxn];
vector<pii> adj[maxn];
bool vis[maxn],bad;

void dfs(int u){
    vis[u]=1;
    for(auto [v,w]: adj[u]){
        if(vis[v]){
            if(color[u]^color[v]^w){
                bad=1;
            }
            continue;
        }
        else{
            color[v]=color[u]^w;
            dfs(v);
        }
    }
}

void orzck(){
    cin >> n >> m;
    rep(n) adj[i].clear(),vis[i]=0;
    rep(n-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        e[i][0]=u,e[i][1]=v;
        res[i]=w;
        if(w>=0){
            int de=__builtin_popcountll(w);
            adj[u].pb({v,de&1}),adj[v].pb({u,de&1});
        }
    }
    rep(m){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        adj[u].pb({v,w}),adj[v].pb({u,w});
    }
    bad=0;
    rep(n) if(!vis[i]) dfs(i);
    if(bad){
        print("NO");
        return;
    }
    print("YES");
    rep(n-1){
        print0(e[i][0]+1),print0(e[i][1]+1);
        if(res[i]>=0) print(res[i]);
        else print(color[e[i][0]]^color[e[i][1]]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
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