#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef rg
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
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
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
vector<ll>v[100005];
ll c[100005][3];
ll cl[100005];
ll dfs(ll x,ll y,ll z,ll p)
{
    ll ans=c[x][y];
    ll bt=3-y-z;
    for(auto xx:v[x])
    {
        if(xx!=p)
        {
            ans+=dfs(xx,bt,y,x);
        }
    }
    return ans;
}
void dfs1(ll x,ll y,ll z,ll p)
{
    cl[x]=y;
    ll bt=3-y-z;
    for(auto xx:v[x])
    {
        if(xx!=p)
        {
            dfs1(xx,bt,y,x);
        }
    }
}
void solve()
{   
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>c[i][0];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>c[i][1];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>c[i][2];
    }
    rep(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll st=0;
    for(ll i=1;i<=n;i++)
    {
        if(v[i].size()>2)
        {
            cout<<"-1"<<endl;
            return;
        }
        if(v[i].size()==1)
        {
            st=i;
        }
    }
    ll a=0,b=0;
    ll c=INF;
    rep(i,3)
    {
        rep(j,3)
        {
            if(i==j)
            {
                continue;
            }
            ll xx=dfs(st,i,j,-1);
            if(c>xx)
            {
                a=i,b=j;
                c=xx;
            }
        }
    }
    dfs1(st,a,b,-1);
    cout<<c<<endl;
    rep(i,n)
    {
        cout<<cl[i+1]+1<<' ';
    }

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
    
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    end_routine();
}