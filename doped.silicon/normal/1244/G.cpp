#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #ifndef rg
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #endif
 
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

#define INF 1000000000000000
#define MOD 1000000007
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

 
#ifdef rg
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
inline bool equals(double a, double b) {return fabs(a - b) < 1e-9;}
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll modpow(ll b, ll e) {
    ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans;}
char inv(char c)
{
    if(c=='B')
        return 'W';
    return 'B';
} 
void solve()
{
    multiset<ll>s;
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        s.insert(i+1);
        s.insert(i+1);
    }
    ll sum=n*(n+1)/2;
    if(m<sum)
    {
        cout<<"-1";
        return;
    }
    ll ans[n]={0};
    ll k=0;
    ll last=n;
    ll ix=0;
    rep(i,n)
    {
        ans[i]=n-i;
    }
    for(ll i=2*n;i>=1;i--)
    {
        ll bt=(i+1)/2;
        if(sum-last+bt+k<=m&&bt>=last&&ix<n)
        {
            sum-=last;
            last--;
            k+=bt;
            ans[ix]=bt;
            ix++;
        }
        if(sum+k==m)
        {
            break;
        }
    }
    ll an1[n]={0};
    ll an2[n]={0};
    ll sa1[n+1]={0};
    ll sa2[n+1]={0};
    ll s1[n+1]={0};
    rep(i,n)
    {
        an1[i]=-1;
        an2[i]=-1;
    }
    rep(i,n)
    {
        if(s1[ans[i]]==0)
        {
            an1[i]=ans[i];
            s1[ans[i]]=1;
            sa1[ans[i]]=1;
        }
        else
        {
            an2[i]=ans[i];
            sa2[ans[i]]=1;
        }
    }
    ll p1=n,p2=n;
    rep(i,n)
    {
        if(an1[i]==-1)
        {
            while(sa1[p1]==1)
            {
                p1--;
            }
            an1[i]=p1;
            sa1[p1]=1;
        }
        if(an2[i]==-1)
        {
            while(sa2[p2]==1)
            {
                p2--;
            }
            an2[i]=p2;
            sa2[p2]=1;
        }
    }
    cout<<sum+k<<endl;
    rep(i,n)
    {
        cout<<an1[i]<<' ';
    }
    cout<<endl;
    rep(i,n)
    {
        cout<<an2[i]<<' ';
    }
    cout<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
    #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    end_routine();
}