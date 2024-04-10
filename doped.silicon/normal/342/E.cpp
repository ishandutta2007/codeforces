// clang-format off
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
typedef pair<int, int> pi;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pi, int> piii;
typedef vector<int> vi;
typedef vector<pi> vii;

#define INF 4557430888798830399ll
#define MOD 1000000007
// #define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define f first
#define s second
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

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


// remove sz from our template before using
const int N = 250005;
const int LOGN = 19;
vector<int> g[N];
bool centroid[N];
int dp[LOGN][N], depth[N], par[N], sz[N];
int n, q;
ll ans[N];
void dfs2(int u,int p){
    sz[u] = 1;
    for(int v : g[u])
        if(v != p && !centroid[v]){
            dfs2(v, u);
            sz[u] += sz[v];
        }
}
int get(int u,int p,int S){
    for(int v : g[u])
        if(v != p && !centroid[v] && sz[v] > S / 2)
            return get(v, u, S);
    return u;
}
int solve(int u){
    dfs2(u, 0);
    int c = get(u, 0, sz[u]);
    centroid[c] = 1;
    for(int v : g[c])
        if(!centroid[v])
            par[solve(v)] = c;
    return c;
}
void dfs1(int u,int p){
    dp[0][u] = p;
    depth[u] = depth[p] + 1;
    for(int v : g[u])
        if(v != p)
            dfs1(v, u);
}
void preprocess(){
    fr(k, 1, LOGN - 1)
        fr(i, 1, n)
            dp[k][i] = dp[k - 1][dp[k - 1][i]];
}
int lca(int u,int v){
    if(depth[u] < depth[v]) swap(u, v);
    for(int k = LOGN - 1; k >= 0; k--)
        if(depth[dp[k][u]] >= depth[v])
            u = dp[k][u];
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--)
        if(dp[k][u] != dp[k][v]) u = dp[k][u], v = dp[k][v];
    return dp[0][u];
}
int dis(int u,int v){ return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

void paint(ll x)
{
	ll y=x;
	while(y!=0)
	{
		ans[y]=min(ans[y],dis(y,x));
		// trace(y,par[y],dis(y,x));
		y=par[y];
	}
}
ll query(ll x)
{
	ll y=x;
	ll bt=INF;
	while(y!=0)
	{
		bt=min(bt,ans[y]+dis(y,x));
		// trace(lca(x,y));
		// trace(y,par[y],ans[y],dis(y,x));
		y=par[y];
	}
	return bt;
}
void solve() 
{
	ll m;
	cin>>n>>m;
	rep(i,n-1)
	{
		ll x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
    dfs1(1, 0);
    preprocess();
    solve(1);
    // cout<<"ds";?
    rep(i,n)
    {
    	ans[i+1]=INF;
    }
    paint(1);
    rep(i,m)
    {
    	ll x,y;
    	cin>>x>>y;
    	if(x==1)
    	{
    		paint(y);
    	}
    	else
    	{
    		cout<<query(y)<<endl;
    	}
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
    // ll n;
    // while(cin>>n)
    {
    	// if(n==0)
    	// {
    	// 	break;
    	// }
        solve();
    }
    end_routine();
}