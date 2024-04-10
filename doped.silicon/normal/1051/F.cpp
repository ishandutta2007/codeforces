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

// #define int long long
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
#define inf 1000000000
#define MOD  998244353
// #define EPS 1e-7
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


ll dsu[100005];
const ll N=100005;
ll tim=1;
ll up[N][20];
ll dp[N][20];
vector<pair<ll,ll>>adj[N];
ll tin[N];
ll tout[N];                                 //0 based index of tree, call dfs0(0,0) for preprocessing.
void dfs0(ll x,ll p,ll w)
{
    tin[x]=tim++;
    up[x][0]=p;
    dp[x][0]=w;
    for(ll i=1;i<=19;i++)
    {
        up[x][i]=up[up[x][i-1]][i-1];
        dp[x][i]=dp[up[x][i-1]][i-1]+dp[x][i-1];
    }
    for(auto z:adj[x])
        if(z.ff!=p)
            dfs0(z.ff,x,z.ss);
    tout[x]=tim++;
}
bool isan(ll x, ll y)
{
    if(x==0)
    return 1;
    return tin[x]<=tin[y]&&tout[y]<=tout[x];
}
ll lca(ll x,ll y)
{
    if(isan(x,y)) return x;
    if(isan(y,x)) return y;
    for(ll i=19;i>=0;i--)
    {
        if(!isan(up[x][i],y))
            x=up[x][i];
    }
    return up[x][0];
}
ll dis(ll x,ll y)
{
    if(x==y)
        return 0;
    ll z=0;
    for(ll i=19;i>=0;i--)
    {
        if(!isan(up[x][i],y))
        {
            z+=dp[x][i];
            x=up[x][i];
        }
    }
    return z+dp[x][0];
}
ll dish(ll x,ll y)
{
    ll lc=lca(x,y);
    return dis(x,lc)+dis(y,lc);
}
int fpar(int i) 
{
    return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
void merge(int i, int j) 
{
    if(i!=j) 
    {
        if(dsu[i]>dsu[j])
            swap(i,j);
        dsu[i]+=dsu[j];
        dsu[j]=i;
    }
}

map<pair<ll,ll>,ll>ma;
ll fw[45][45];
ll dx[45][2];

void solve()
{
    ll n,m;
    cin>>n>>m;
    rep(i,100005)
    {
        dsu[i]=-1;
    }
    set<ll>s;
    vector<ll>v;
    rep(i,m)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        ll xy=fpar(x);
        ll yx=fpar(y);
        if(xy==yx)
        {
            s.insert(x);
            s.insert(y);
            ma[mp(x,y)]=z;
            ma[mp(y,x)]=z;
        }
        else
        {
            merge(xy,yx);
            adj[x].pb(mp(y,z));
            adj[y].pb(mp(x,z));
        }

    }
    for(auto z:s)
    {
        v.pb(z);
    }
    dfs0(0,0,0);
    ll q;
    cin>>q;
    rep(i,45)
    {
        rep(j,45)
        {
            fw[i][j]=INF;
        }
    }
    rep(i,v.size())
    {
        for(ll j=i+1;j<v.size();j++)
        {
            fw[i][j]=dish(v[i],v[j]);
            if(ma.find(mp(v[i],v[j]))!=ma.end())
            {
                fw[i][j]=min(fw[i][j],ma[mp(v[i],v[j])]);
            }
            fw[j][i]=fw[i][j];
        }
    }
    ll n1=v.size();
    for (int k = 0; k < n1; ++k) {
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n1; ++j) {
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]); 
            }
        }
    }
    // trace(dp[2][0]);
    // trace(dp[2][1]);
    // trace(dp[1][0]);
    rep(i,q)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        ll an=dish(x,y);
        rep(j,v.size())
        {
            dx[j][0]=dish(x,v[j]);
        }
        rep(j,v.size())
        {
            dx[j][1]=dish(y,v[j]);
        }
        rep(j,v.size())
        {
            for(ll k=j+1;k<v.size();k++)
            {
                an=min(an,min(dx[j][0]+dx[k][1],dx[j][1]+dx[k][0])+fw[j][k]);
            }
        }
        cout<<an<<endl;


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
        // cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    end_routine();
}