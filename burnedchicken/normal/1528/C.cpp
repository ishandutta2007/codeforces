#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
#include <bits/extc++.h>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=300005;

//i_am_noob
#define wiwihorz  
int n,cur,res,l[maxn],r[maxn],id[maxn];
vector<int> adj1[maxn],adj2[maxn];
ordered_set st;

void dfs2(int u, int par){
    bug(u,par);
    l[u]=++cur;
    id[l[u]]=u;
    for(auto v: adj2[u]) dfs2(v,u);
    r[u]=cur;
    bug(u,l[u],r[u]);
}

void dfs1(int u, int par){
    bug(u,par);
    int flag=-1;
    int x=st.order_of_key(l[u]);
    bug(x);
    if(x){
        int y=*st.find_by_order(x-1);
        bug(y);
        y=id[y];
        if(l[u]<=r[y]) flag=l[y],st.erase(l[y]);
    }
    st.insert(l[u]);
    res=max(res,sz(st));
    bug(sz(st));
    for(auto v: adj1[u]) dfs1(v,u);
    st.erase(l[u]);
    if(flag!=-1) st.insert(flag);
}

void orzck(){
    cin >> n;
    rep(n) adj1[i].clear(),adj2[i].clear();
    rep(n-1){
        int u;
        cin >> u;
        u--;
        adj1[u].pb(i+1);
    }
    rep(n-1){
        int u;
        cin >> u;
        u--;
        adj2[u].pb(i+1);
    }
    st.clear();
    cur=res=0;
    dfs2(0,-1);
    cur=0;
    dfs1(0,-1);
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