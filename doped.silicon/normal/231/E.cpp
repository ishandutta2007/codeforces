// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef ritick
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000000000
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef ritick
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
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng32)
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }



// Description:
// B -> stores the nodes in a bcc
// bcc[u] -> which bcc u is in.
// cmpno -> number of bcc's
// to just get bridges call get_bridge
struct BCC{
    #define N 100005
    vector<int> tree[N], g[N], B[N];
    int U[N], V[N], temp[N], bcc[N], ind[N], T, cmpno, m, n;
    bitset<N> vis, bridge;
    vector<int> Q[N];
    void init(int _n){ n = _n, cmpno = 0, T = 0, m = 0; }
    void reset(int n){
        fr(i, 1, n){
            g[i].clear(), tree[i].clear(), B[i].clear();
            ind[i] = 0;
        }
        bridge.reset();
    }
    int adj(int u,int e){ return U[e] == u ? V[e] : U[e]; }
    void addedge(int u,int v){
        U[m] = u, V[m] = v;
        g[u].pb(m), g[v].pb(m);
        m++;
    }
    void get_bridges(){
        fr(i, 1, n)
            if(!vis[i])
                dfs1(i, -1);
        vis.reset();
    }
    void go(){
        get_bridges();
        fr(i, 1, n)
            if(!vis[i]){
                cmpno++; dfs2(i);
            }
        vis.reset();
    }
    int dfs1(int u,int e){
        vis[u] = 1;
        temp[u] = T++;
        int t = temp[u];
        for(int id: g[u]){
            int v = adj(u, id);
            if(!vis[v]) t = min(t, dfs1(v, id));
            else if(id != e) t = min(t, temp[v]);
        }
        if(t == temp[u] && e != -1) bridge[e] = 1;
        return t;
    }
    void dfs2(int u){
        int cur_cmp = cmpno;
        Q[cur_cmp].pb(u);
        bcc[u] = cur_cmp;
        B[cur_cmp].pb(u);
        vis[u] = 1;
        while(Q[cur_cmp].size() != ind[cur_cmp])
        {
            int u = Q[cur_cmp][ind[cur_cmp]];    
            ind[cur_cmp]++;
            for(int e: g[u])
            {
                int v = adj(u, e);
                if(vis[v]) continue;
                if(bridge[e])
                {
                    cmpno++;
                    tree[cur_cmp].pb(cmpno);
                    tree[cmpno].pb(cur_cmp);
                    dfs2(v);
                }
                else
                {
                    Q[cur_cmp].pb(v);
                    vis[v] = 1;
                    bcc[v] = cur_cmp;
                    B[cur_cmp].pb(v);
                }
            }
        }
    }
    #undef N
}bc;
ll dp[100005][20];
ll up[100005][20];
ll dpt[100005];

void dfs(ll x,ll p)
{
    dpt[x]=dpt[p]+1;
    up[x][0]=p;
    for(ll i=1;i<20;i++)
    {
        up[x][i]=up[up[x][i-1]][i-1];
        dp[x][i]=dp[x][i-1]+dp[up[x][i-1]][i-1];
    }
    for(auto z:bc.tree[x])
    {
        if(z!=p)
            dfs(z,x);
    }
}

ll find(ll x,ll y)
{
    if(dpt[x]<dpt[y])
    {
        swap(x,y);
    }
    ll ans=0;
    for(ll i=19;i>=0;i--)
    {
        if(dpt[up[x][i]]>=dpt[y]) ans+=dp[x][i], x=up[x][i];
    }
    if(x==y)
        return ans+dp[x][0];
    for(ll i=19;i>=0;i--)
    {
        if(up[x][i]!=up[y][i]) ans+=dp[x][i]+dp[y][i],x=up[x][i],y=up[y][i];
    }
    return ans+dp[x][1]+dp[y][0];
}
ll pwr[100005];
void solve() 
{   
    ll n,m;
    cin>>n>>m;
    bc.init(n);
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        bc.addedge(x,y);
    }
    bc.go();
    for(ll i=1;i<=bc.cmpno;i++)
    {
        if(bc.B[i].size()>1)
         dp[i][0]=1;
    }
    dfs(1,0);
    pwr[0]=1;
    for(ll i=1;i<=100005;i++)
    {
        pwr[i]=pwr[i-1]*2%MOD;
    }
    ll x;
    cin>>x;
    rep(i,x)
    {
        ll a,b;
        cin>>a>>b;
        // trace(find(bc.bcc[a],bc.bcc[b]));
        cout<<pwr[find(bc.bcc[a],bc.bcc[b])]<<endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
    #ifdef ritick
        cin.exceptions(cin.failbit);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}