// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000ll
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

#ifdef bhartiya
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

const int N = 150005;
const int LOGN = 19;
vector<int> g[N];
bool centroid[N];
int par[N], sz[N];
int fs[N],sn[N],sum[N];
int n, q;
int val[N];
ll ans;
struct LiChao
{
    struct line
    {
        ll a, b;
        line() { a = 0; b = 0; }
        line(ll _a, ll _b) { a = _a; b = _b; }
        ll eval(ll x) { return a * x + b; }
    };
    struct node
    {
        node *l, *r; line f;
        node() { f = line(); l = NULL; r = NULL; }
        node(ll a, ll b) { f = line(a, b); l = NULL; r = NULL; }
        node(line v) { f = v; l = NULL; r = NULL; }
    };
    typedef node* pnode;
    pnode root; ll sz;
    void init(ll _sz) { sz = _sz + 1; root = NULL; }
    void add_line(ll a, ll b) { line v = line(a, b); insert(v, -sz, sz, root); }
    ll query(ll x) { return query(x, -sz, sz, root); }
    void insert(line &v, ll l, ll r, pnode &nd)
    {
        if(!nd) { nd = new node(v); return; }
        ll trl = nd->f.eval(l), trr = nd->f.eval(r);
        ll vl = v.eval(l), vr = v.eval(r);
        if(trl >= vl && trr >= vr) return;
        if(trl < vl && trr < vr) { nd->f = v; return; }
        ll mid = (l + r) >> 1;
        if(trl < vl) swap(nd->f, v);
        if(nd->f.eval(mid) > v.eval(mid)) insert(v, mid + 1, r, nd->r);
        else swap(nd->f, v), insert(v, l, mid, nd->l);
    }
    ll query(ll x, ll l, ll r, pnode &nd)
    {
        if(!nd) return -INF;
        if(l == r) return nd->f.eval(x);
        ll mid = (l + r) >> 1;
        if(mid >= x) return max(nd->f.eval(x), query(x, l, mid, nd->l));
        return max(nd->f.eval(x), query(x, mid + 1, r, nd->r));
    }
};
ll sx=0;
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
void dfsx(ll x,ll d,ll p)
{
    sx++;
    fs[x]=fs[p]+d*val[x];
    sn[x]=sn[p]+sum[p]+val[x];
    sum[x]=sum[p]+val[x];
    ans=max(ans,sn[x]);
    ans=max(ans,fs[x]+sum[x]);
    for(auto z:g[x])
    {
        if(!centroid[z]&&z!=p)
        {
            dfsx(z,d+1,x);
        }
    }
}
vector<pair<ll,ll>>vz;
void add(ll x,ll p,ll d)
{
    vz.pb(mp(x,d));
    for(auto z:g[x])
    {
        if(!centroid[z]&&z!=p)
        {
            add(z,x,d+1);
        }
    }
}
int solve(int u){
    dfs2(u, 0);
    int c = get(u, 0, sz[u]);
    centroid[c] = 1;
    // trace(c);
    fs[c]=0;
    sn[c]=val[c];
    sum[c]=val[c];
    vector<ll>vx;
    sx=5;
    for(int v:g[c])
    {
        if(centroid[v])
            continue;
        vx.pb(v);
        dfsx(v,1,c);
    }
    LiChao lic1,lic2;
    lic1.init(sx);
    lic2.init(sx);
    for(int v:vx)
    {
        vz.clear();
        add(v,v,2);
        for(auto z:vz)
        {
            ll a=z.ff;
            ll b=z.ss;
            ans=max(ans,lic1.query(b)+sn[a]);
        }
        for(auto z:vz)
        {
            ll a=z.ff;
            lic1.add_line(sum[a]-val[c],fs[a]);
        }
        
    }
    reverse(all(vx));
    for(int v:vx)
    {
        vz.clear();
        add(v,v,2);
        for(auto z:vz)
        {
            ll a=z.ff;
            ll b=z.ss;
            ans=max(ans,lic2.query(b)+sn[a]);
        }
        for(auto z:vz)
        {
            ll a=z.ff;
            lic2.add_line(sum[a]-val[c],fs[a]);
        }
        
    }

    for(int v : g[c])
        if(!centroid[v])
            par[solve(v)] = c;
    return c;
}

void solve() 
{
    ll n;
    cin>>n;
    rep(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    rep(i,n)
    {
        cin>>val[i+1];
    }
    ll r = solve(1);
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   //cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {
        solve();
    }
    end_routine();
}