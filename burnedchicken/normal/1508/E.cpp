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
const int maxn=300005;

//i_am_noob
//#define wiwihorz  

int n,a[maxn],b[maxn],res,child[maxn],lst,par[maxn],dep[maxn],flag;
vector<int> adj[maxn],vec,vec1,vec2;

void dfs(int u, int fa){
    par[u]=fa;
    dep[u]=fa==-1?0:dep[fa]+1;
    for(auto v: adj[u]) if(v!=fa) dfs(v,u);
}

void dfs2(int u, int fa){
    vec.pb(u);
    if(a[u]>=lst) vec2.pb(a[u]);
    for(auto v: adj[u]) if(v!=fa) dfs2(v,u);
    bug(a[u]);
    if(a[u]<lst){
        vec1.pb(a[u]),res+=dep[u];
        if(flag) flag++;
    }
    else if(flag==0) flag++;
}

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    child[0]=sz(adj[0]);
    rep2(i,1,n) child[i]=sz(adj[i])-1;
    dfs(0,-1);
    rep(n) b[a[i]]=i;
    lst=n;
    rep(n){
        if(child[b[i]]==0) child[par[b[i]]]--;
        else{
            lst=i;
            break;
        }
    }
    bug(lst);
    if(lst<n) for(int j=b[lst]; j; j=par[j]){
        swap(a[j],a[par[j]]),res++;
        bug(j);
        for(auto k: adj[par[j]]) if(k!=par[par[j]]&&a[k]>a[par[j]]&&a[k]<a[j]){
            print("NO");
            return;
        }
    }
    rep(n) bug(i,a[i]);
    rep(n) sort(all(adj[i]),[](int i1, int i2){return a[i1]<a[i2];});
    dfs2(0,-1);
    bug(vec);
    bug(flag);
    if(flag>=2||(!is_sorted(all(vec1)))||(!is_sorted(all(vec2)))){
        print("NO");
        return;
    }
    rep(n) b[vec[i]]=i+1;
    print("YES"),print(res);
    rep(n) print0(b[i]);
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