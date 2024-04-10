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



ll k;
ll mat[100][100];
ll F[100][100];
void unit(ll F[100][100])
{
    rep(i,k)
    {
        rep(j,k)
        {
            F[i][j]=0;
        }
        F[i][i]=1;
    }
}
void multiply(ll A[100][100],ll B[100][100],ll mod)
{
    ll c[k][k];
    rep(i,k)
    {
        rep(j,k)
        {
            ll x=0;
            rep(jj,k)
            {
                x=(x+A[i][jj]*B[jj][j]%mod)%mod;
            }
            c[i][j]=x;
        }
    }
    rep(i,k)
    {
        rep(j,k)
        {
            A[i][j]=c[i][j];
        }
    }
}
void power(ll F1[100][100], ll n1,ll mod) 
{ 
  if( n1 == 0) 
      return; 
  power(F1, n1/2,mod); 
  multiply(F1, F1,mod); 
  
  if (n1%2 != 0) 
     multiply(F1, mat,mod); 
} 
ll fibo(ll n,ll mod=MOD) 
{
    if(n==1)
    {
        return 1%mod;
    }
    n--;
    k=2;
    unit(F);
    rep(i,2)
    {
        rep(j,2)
        {
            mat[i][j]=1;
        }
    }
    mat[1][1]=0;
    power(F,n,mod);
    return F[0][0];

}

    ll m,l,r;
ll find(ll x)
{
    if(x==0)
    {
        return 0;
    }
    return (r/x)-(l+x-1)/x+1;
}
void solve()
{
    ll k;
    cin>>m>>l>>r>>k;
    ll ans=1;
    for(ll i=1;i*i<=r;i++)
    {   
        if(find(i)>=k)
        {
            ans=max(ans,i);
        }
        if(find(r/i)>=k)
        {
            ans=max(ans,r/i);
        }
        if(find(l/i)>=k)
        {
            ans=max(ans,l/i);
        }
    }
    // trace(ans);a

    cout<<fibo(ans,m)<<endl;
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