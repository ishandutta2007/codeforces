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
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=400005;

//i_am_noob
//#define wiwihorz  
int n,m,cur,curscc,scc[maxn],in[maxn],res;
vector<int> id[maxn],a[maxn],adj[maxn],radj[maxn],ord;
bool vis[maxn];

void add_edge(int x, int y){adj[x].pb(y),radj[y].pb(x);}

void rdfs(int u){
    vis[u]=1;
    for(auto v: radj[u]) if(!vis[v]) rdfs(v);
    ord.pb(u);
}

bool flag;

void dfs(int u){
    vis[u]=1;
    scc[u]=curscc;
    bug(u,scc[u]);
    for(auto v: adj[u]){
        if(vis[v]&&scc[v]!=scc[u]) in[scc[v]]++;
        if(!vis[v]) dfs(v);
    }
}

void orzck(){
    cin >> n >> m;
    rep(n) rep1(j,m){
        char c;
        cin >> c;
        if(c=='#') a[j].pb(i),id[j].pb(cur++),bug(j,i,cur);
    }
    rep(m) rep1(j,sz(a[i])){
        if(j&&a[i][j-1]==a[i][j]-1) add_edge(id[i][j],id[i][j-1]);
        if(j<sz(a[i])-1) add_edge(id[i][j],id[i][j+1]);
        if(i&&sz(a[i-1])&&a[i-1].back()>=a[i][j]){
            int x=lower_bound(all(a[i-1]),a[i][j])-a[i-1].begin();
            add_edge(id[i][j],id[i-1][x]);
        }
        if(i<m-1&&sz(a[i+1])&&a[i+1].back()>=a[i][j]){
            int x=lower_bound(all(a[i+1]),a[i][j])-a[i+1].begin();
            add_edge(id[i][j],id[i+1][x]);
        }
    }
    rep(cur) if(!vis[i]) rdfs(i);
    reverse(all(ord));
    memset(vis,0,sizeof vis);
    for(auto i: ord) if(!vis[i]){
        flag=1;
        dfs(i);
        curscc++;
    }
    rep(curscc) if(!in[i]) res++,bug(i);
    print(res);
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