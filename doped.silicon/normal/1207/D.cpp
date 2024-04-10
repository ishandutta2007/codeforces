#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef bhartiya
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

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define INF 1000000000000000000ll
#define MOD 998244353
#define mod 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)
#define ff first
#define ss second
 
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar,val) memset(ar, val, sizeof(ar))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

 
#ifdef bhartiya
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define end_routine() 
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif
 
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) {return fabs(a - b) < 1e-9;}
int gcd(int a, int b){ return b==0 ? a : gcd(b, a%b); }
ll modpow(ll b, ll e) {
    ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans;}
ll f[300005];
void solve()
{
    f[0]=1;
    for(ll i=1;i<=300000;i++)
    {
        f[i]=f[i-1]*i%MOD;
    }
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v;
    rep(i,n)
    {
        ll x,y;
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    ll ans=1;
    sort(all(v));
    bool xx=1;
    rep(i,n-1)
    {
        if(v[i+1].ss<v[i].ss)
            xx=0;
    }
    map<ll,ll>m;
    map<pair<ll,ll>,ll>ma;
    for(ll i=1;i<=n;i++)
    {
        ans=ans*i%MOD;
    }
    if(xx)
    {
        ll bz=1;
        for(auto x:v)
        {
            if(ma.count(x)==0)
            {
                ma[x]=1;
            }
            else
            {
                ma[x]++;
            }
        }
        for(auto x:ma)
        {
            bz=bz*f[x.ss]%MOD;
        }
        ans=(ans+bz)%MOD;
    }
    for(auto x:v)
    {
        if(m.count(x.ff)==0)
        {
            m[x.ff]=1;
        }
        else
        {
            m[x.ff]++;
        }
    }
    ll bxx=1;
    for(auto x:m)
    {

        bxx=bxx*f[x.ss]%MOD;
    }
    ans=(ans+MOD-bxx)%MOD;
    // cout<<ans<<endl;
    m.clear();
    for(auto &x:v)
    {
        swap(x.ff,x.ss);
    }
    sort(all(v));
    for(auto x:v)
    {
        if(m.count(x.ff)==0)
        {
            m[x.ff]=1;
        }
        else
        {
            m[x.ff]++;
        }
    }
    bxx=1;
    for(auto x:m)
    {
        bxx=bxx*f[x.ss]%MOD;
    }
    ans=(ans+MOD-bxx)%MOD;
    cout<<ans<<endl;

}

signed main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
    #ifdef rg
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int begtime = clock();
    ll t=1;
    // cin>>t;
    for(ll i=1;i<=t;i++)
    {
        solve();
    }

    // cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
}