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
// #define PI 3.1415926535897932385
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
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }


ll n1=200006;//size of fenwick tree
ll bt[200006][2];
ll getSum(ll x,ll k)
{
    ll sum=0;
    for(;x>=1;x-=(x&-x))
        sum+=bt[x][k];
    return sum;
}
void update(ll x, ll d,ll k)
{
    for(;x<=n1;x+=(x&-x))
    {
        bt[x][k]+=d;
    }
}
ll get(ll x,ll y,ll k)
{
    return getSum(y,k)-getSum(x-1,k);
}
ll tin[200005];
ll tout[200005];
ll a[200005];
ll b[200005];
ll c[200005];
ll vis[200005];
ll pa[200005];
vector<ll>v[200005];
ll tim=1;
void dfs(ll x,ll p)
{
    tin[x]=tim++;
    pa[x]=p;
    for(auto z:v[x])
    {
        if(z!=p)
        {
            dfs(z,x);
        }
    }
    tout[x]=tim-1;
    // trace(x,tin[x],tout[x]);
}
vector<pair<ll,ll>>vx;
void mark(ll x)
{
    if(vis[x])
    {
        return;
    }
    vis[x]=1;
    for(auto z:v[x])
    {
        if(z!=pa[x])
            mark(z);
    }
}
void solve()
{
    ll n,m;
    cin>>n;
    rep(i,n)
    {
        ll y,z;
        cin>>c[i+1]>>b[i+1]>>a[i+1];
        vx.pb(mp(c[i+1],i+1));
    }
    rep(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }   
    dfs(1,1);
    rep(i,n)
    {
        ll y=b[i+1];
        ll z=a[i+1];
        // trace(y,z);
        if(y+z==1)
        {
            trace(tin[i+1],z);
            update(tin[i+1],1,y);
        }
    }
    sort(all(vx));
    ll ans=0;
    for(auto z:vx)
    {
        if(vis[z.ss])
        {
            continue;
        }
        ll x=get(tin[z.ss],tout[z.ss],0);
        ll y=get(tin[z.ss],tout[z.ss],1);
        // trace(z,x,y);
        if(z.ss==1&&x!=y)
        {
            cout<<"-1";
            return;
        }
        x=min(x,y);
        ans+=z.ff*x*2;
        update(tin[z.ss],-x,0);
        update(tin[z.ss],-x,1);
        mark(z.ss);
    }

    cout<<ans<<endl;

    



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