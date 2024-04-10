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
 
// #define int long long 
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
const ll N=100005;
vector<ll>v[N][4];
// ll ar[N][4];
bool hbt;
set<pair<ll,ll>>s;
bool check(ll x,ll y)
{
    if(s.find(mp(x,y))!=s.end())
    {
        return 0;
    }
    s.insert(mp(x,y));
    return 1;
}
ll l,r,u,d;
void solve()
{
    ll di=0;
    ll cnt=1;
    ll n,m;
    ll k;
    cin>>n>>m>>k;
    swap(n,m);
    l=0,r=m-1,u=n-1,d=0;
    rep(i,k)
    {
        ll x,y;
        cin>>x>>y;
        x--,y--;
        v[x][0].pb(y);
        v[x][2].pb(y);
        v[y][1].pb(x);
        v[y][3].pb(x);
    }
    rep(i,n-1)
    {
        sort(all(v[i][0]));
        sort(all(v[i][1]));
        sort(all(v[i][2]));
        sort(all(v[i][3]));
        reverse(all(v[i][2]));
        reverse(all(v[i][3]));
    }
    ll x=0,y=0;
    while(true)
    {
        ll p=0;
        if(di==0)
        {
            ll nx=v[x][0].size();
            ll ny=y;
            while(p<nx&&y>v[x][0][p])
            {
                p++;
            }
            if(p>=v[x][0].size())
            {
                ny=u;
            }
            else
            {
                ny=v[x][0][p]-1;
            }
            if(ny>u)
            {
                cnt+=u-y;
                y=u;
            }
            else
            {
                cnt+=ny-y;
                y=ny;
                u=ny;
            }
            if(!check(x,y))
            {
                break;
            }
            l++;
        }
        else if(di==1)
        {
            ll nx=v[y][di].size();
            ll ny=x;
            while(p<nx&&x>v[y][di][p])
            {
                p++;
            }
            if(p>=v[y][di].size())
            {
                ny=r;
            }
            else
            {
                ny=v[y][di][p]-1;
            }
            if(ny>r)
            {
                cnt+=r-x;
                x=r;
            }
            else
            {
                cnt+=ny-x;
                x=ny;
                r=ny;
            }
            if(!check(x,y))
            {
                break;
            }
            u--;
        }
        else if(di==2)
        {
            ll nx=v[x][di].size();
            ll ny=y;
            while(p<nx&&y<v[x][di][p])
            {
                p++;
            }
            if(p>=v[x][di].size())
            {
                ny=d;
            }
            else
            {
                ny=v[x][di][p]+1;
            }
            // trace(ny,d,y);
            if(ny<d)
            {
                cnt+=y-d;
                y=d;
            }
            else
            {
                cnt+=y-ny;
                y=ny;
                d=ny;
            }
            if(!check(x,y))
            {
                break;
            }
            r--;
        }
        else if(di==3)
        {
            ll nx=v[y][di].size();
            ll ny=x;
            while(p<nx&&x<v[y][di][p])
            {
                p++;
            }
            if(p>=v[y][di].size())
            {
                ny=l;
            }
            else
            {
                ny=v[y][di][p]+1;
            }
            
            if(ny<l)
            {
                cnt+=x-l;
                x=l;
            }
            else
            {
                cnt+=x-ny;
                x=ny;
                l=ny;
            }
            if(!check(x,y))
            {
                break;
            }
            d++;
        }
        di++;
        di%=4;
        // trace(x,y);
    }
    // trace(cnt);
    if(cnt==n*m-k)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No";
    }
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