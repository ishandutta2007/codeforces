#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

#define int long long
#define ull unsigned long long
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
template<int maxn>
struct dsu{
    int par[maxn],siz[maxn];
    dsu(){rep(maxn) par[i]=i,siz[i]=1;}
    int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}
    bool Union(int x, int y){
        x=Find(x),y=Find(y);
        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x,y);
        par[y]=x;
        siz[x]+=siz[y];
        return true;
    }
};
dsu<maxn> d;

int n,a[maxn],u,v,l[maxn],r[maxn],cnt,id[maxn],val[maxn],ans;
vector<int> adj[maxn],vec[maxn],res;

void dfs(int u, int par){
    if(u&&sz(adj[u])==1){
        l[u]=cnt,r[u]=++cnt;
        return;
    }
    l[u]=inf,r[u]=-inf;
    for(auto v: adj[u]) if(v!=par){
        dfs(v,u);
        l[u]=min(l[u],l[v]),r[u]=max(r[u],r[v]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n;
    rep(n) cin >> a[i];
    rep(n-1){
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(0,-1);
    rep(n) id[i]=i;
    sort(id,id+n,[](int i, int j){return a[i]<a[j];});
    val[id[0]]=0;
    rep2(i,1,n) val[id[i]]=val[id[i-1]]+(a[id[i-1]]!=a[id[i]]);
    rep(n) vec[val[i]].pb(i);
    rep(n) if(sz(vec[i])){
        for(auto j: vec[i]) if(d.Find(l[j])!=d.Find(r[j])) res.pb(j);
        for(auto j: vec[i]) if(d.Union(l[j],r[j])) ans+=a[j];
    }
    sort(all(res));
    print(ans,sz(res));
    for(auto i: res) print0(i+1);
    cout << "\n";
    return 0;
}