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



const int n1=20000;
ll f[n1];
ll inv[n1];
void pre()
{
    f[0]=1;
    for(ll i=1;i<=n1-2;i++)
        f[i]=(f[i-1]*i)%MOD;
    inv[n1-2]=modpow(f[n1-2],MOD-2,MOD);
    for(ll i=n1-3;i>=0;i--)
        inv[i]=((i+1)*inv[i+1])%MOD;
}
ll ncr(ll n,ll r)
{
    if(n<0||r<0)
    {
        return 0;
    }
    if(r>n)return 0;
        return (((f[n]*inv[n-r])%MOD)*inv[r])%MOD;
}


ll findx(ll s,ll p, ll m)
{
    if(s<0)
    {
        return 0;
    }
    if(s==0&&p==0)
    {
        return 1;
    }
    ll ans=0;
    for(ll i=0;i<=p;i++)
    {
        if(i&1)
        {
            ans=(ans+MOD-ncr(p,i)*ncr(s-m*i+p-1,p-1)%MOD)%MOD;
        }
        else
        {
            ans=(ans+ncr(p,i)*ncr(s-m*i+p-1,p-1)%MOD)%MOD;
        }
    }
    return ans;
}
void solve()
{
    ll p,s,r;
    cin>>p>>s>>r;
    ll ans=ncr(s-r+p-1,p-1);

    ans=modpow(ans,MOD-2);
    ll bt=ans;
    ans=0;
    for(int i=r;i<=s;i++)
    {
        for(int j=1;j<=p;j++)
        {
            ll xx=modpow(j,MOD-2)%MOD;
            xx=xx*ncr(p-1,j-1)%MOD;
            xx=xx*findx(s-i*j,p-j,i)%MOD;
            // trace(findx(s-i*j,p-j,i));
            // trace(i,j,xx);
            ans=(ans+xx)%MOD;
        }
    }
    ans=ans*bt%MOD;
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
    pre();
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    end_routine();
}