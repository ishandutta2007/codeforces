#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #ifndef ONLINE_JUDGE
// #define broot
// #endif
 
#ifndef broot
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef complex<ld> cd;
 
#define INF 4557430888798830399ll
#define inf 4557430888798830399ll
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)
 
#define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
#define len(x) (int)x.length()
 
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs
#define trav(a, x) for(auto& a : x)
// #define rep(i, a, b) for(int i = a; i < (b); ++i)  // For kactl
// #define FOR(i, a, b) for (int i = (a); i < (b); i++)  // For Benq
// #define F0R(i, a) for (int i = 0; i < (a); i++)  // For Benq
// #define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)  // For Benq
// #define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)  // For Benq
 
#ifdef broot
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif
 
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

#define rsz(x, n) x.resize(n)
#define clr(x) x.clear()
class SCC
{
public:
  int n, cnt; // cnt -> number of scc's formed
  vector<vector<int>> g, rg, sg, comp; // sg -> dag with all nodes compressed.
  vector<int> scc, order;
  vector<bool> vis;
  void reset(){
    clr(g), clr(rg), clr(sg), clr(comp), clr(scc), clr(order), clr(vis);
  }
  void init(int _n)
  {
    reset();
    n = _n, cnt = 0;
    _n += 2;
    rsz(g, _n), rsz(rg, _n), rsz(sg, _n), rsz(comp, _n);
    scc.resize(_n, 0);
    vis.resize(_n, 0);
  }
  void add(int u,int v){
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  void compute(){
    fr(i, 1, n)
      if(!vis[i]) dfs1(i);
    fill(all(vis), 0);
    for(int i = n - 1; i >= 0; i--)
      if(!vis[order[i]])
        dfs2(order[i],++cnt);
  }
  void dfs1(int u){
    vis[u] = 1;
    for(int v: g[u])
      if(!vis[v]) dfs1(v);
    order.pb(u);
  }
  void dfs2(int u,int c){
    vis[u] = 1;
    scc[u] = c;
    comp[c].pb(u);
    for(int v: rg[u]){
      if(!vis[v])
        dfs2(v,c);
      if(vis[v] && c != scc[v])
        sg[scc[v]].pb(c);
    }
  }
};
class TwoSAT{
public:
    vector<int> ans;
    SCC sc;
    int n;
    void reset(){
        ans.clear(), sc.reset();
    }
    void init(int nn){
        reset();
        n = nn;
        ans.resize(2 * n + 1, -1);
        sc.init(2 * n);
    }
    int NOT(int u){
        return (u <= n) ? u + n : u - n;
    }
    void OR(int u,int v){
        sc.add(NOT(u), v);
        sc.add(NOT(v), u);
    }
    void XOR(int u,int v){
        OR(u, v);
        OR(NOT(u), NOT(v));
    }
    void XNOR(int u,int v){
        OR(u, NOT(v));
        OR(NOT(u), v);
    }
    bool solve(){
        sc.compute();
        fr(i, 1, n){
            if(ans[i] == -1){
                if(sc.scc[i] == sc.scc[NOT(i)]) return 0;
                if(sc.scc[i] < sc.scc[NOT(i)]){
                    ans[i] = 0;
                    ans[NOT(i)] = 1;
                }
                else{
                    ans[i] = 1;
                    ans[NOT(i)] = 0;
                }
            }
        }
        return 1;
    }
};

vector<ll>v[100005];
vector<ll>b;
void solve()
{  
    TwoSAT ts;
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        ll x;
        cin>>x;
        b.pb(x);
    }
    rep(i,m)
    {
        ll x;
        cin>>x;
        // trace(x);
        rep(j,x)
        {
            ll bt;
            cin>>bt;
            bt--;
            v[bt].pb(i);
        }
    }
    ts.init(m);
    rep(i,n)
    {
        ll x=v[i][0];
        ll y=v[i][1];
        if(b[i])
        {
            ts.XNOR(x,y);
        }
        else
        {
            ts.XOR(x,y);
        }
    }
    if(ts.solve())
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10);  // cout<<fixed;
    #ifdef broot
        // cin.exceptions(cin.failbit);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t; 
    fr(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}