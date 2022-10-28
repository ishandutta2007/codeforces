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

typedef int ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
// #define MOD 2000000000000000000ll
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
#define sz(x) (int)x.size();

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







bool mat[3005][3005];
ll zl[3005][3005];
ll zr[3005][3005];
ll zd[3005][3005];
ll bt[6005][3005];
ll n1=3005;//size of fenwick tree
ll getSum(ll xx,ll x)
{
    ll sum=0;
    for(;x>=1;x-=(x&-x))
        sum+=bt[xx][x];
    return sum;
}
void update(ll xx,ll x, ll d)
{
    for(;x<=n1;x+=(x&-x))
    {
        bt[xx][x]+=d;
    }
}
ll get(ll xx, ll l,ll r)
{
    return getSum(xx,r)-getSum(xx,l-1);
}
vector<pair<ll,ll>>v[3005];
void solve()
{   
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        rep(j,m)
        {
            char ch;
            cin>>ch;
            if(ch=='z')
                mat[i+1][j+1]=1;
            if(mat[i+1][j+1])
            {
                zl[i+1][j+1]=zl[i+1][j]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(mat[i][j])
            {
                zr[i][j]=zr[i][j+1]+1;
                ll x=j+zr[i][j]-1;
                v[x].pb(mp(i,j));
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(mat[i][j])
            {
                zd[i][j]=zd[i+1][j-1]+1;
            }
        }
    }
    long long ans=0;
    for(int j=m;j>=1;j--)
    {
        for(auto z:v[j])
        {
            update(z.ff+z.ss,z.ss,1);
        }
        for(int i=1;i<=n;i++)
        {
            if(mat[i][j]==0)
            {
                continue;
            }
            ll x=min(zl[i][j],zd[i][j]);
            ll an=get(i+j,j-x+1,j);
            if(n==1&&an==0)
            {
                cout<<j<<x<<endl;
                return;
            }
            ans+=an;
        }
    }
    cout<<ans<<endl;    







}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
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



// 10 10
// zzzz.zzzzz
// ...zzz..zz
// zz.zzzzzzz
// zzzzzz....
// ..zz..zzzz
// zzzzzzzzzz
// z...zzzz..
// zzzzzzzzzz
// zzz....zzz
// ..z.......