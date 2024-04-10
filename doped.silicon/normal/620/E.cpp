#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;
#define ll long long
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
using namespace std;
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld long double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y0 yyyyyy0
auto clk=clock();
#define y1 yyyyyy1
#define setb __builtin_popcount
#define BIT(n) (1<<(n))
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define LSOne(S) (S) & (-S)
inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
 
template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
// template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
template<typename T> string toStr(T x) {stringstream st; st << x; string s; st >> s; return s;}
template<class T>
void splitStr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
 
inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n |= two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}
 
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
 
#define INP "test.inp"
#define OUT "test.out"
 
#define PI 3.1415926535897932385
#define INF 10000000000000000ll
#define EPS 1e-7
#define MAXN 100000
#define MOD 998244353ll
#define dec decr
#define endl '\n'
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll modexp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y %2==1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}
const ll N=400005;
ll st[8*N];
ll tin[N];
ll tout[N];
ll col[N];
ll c[N];
ll lazy[8*N];
ll tim=0;
vector<ll>adj[N];
void dfs0(ll x,ll p)
{
    tin[x]=tim++;
    for(auto z:adj[x])
    {
        if(z!=p)
        {
            dfs0(z,x);
        }
    }
    tout[x]=tim-1;
}
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        st[v]=(1ll<<c[tl]);
        return;
    }
    ll tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v]=(st[2*v]|st[2*v+1]);
}
void push(ll v)
{
    ll x=v;
    if(lazy[x]>0)
    {
        st[2*v]=lazy[x];
        st[2*v+1]=lazy[x];
        lazy[2*x]=lazy[x];
        lazy[2*x+1]=lazy[x];
        lazy[x]=0;
    }
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll z)
{
    if(l>r)
    {
        return ;
    }
    if(tl==l&&tr==r)
    {
        st[v]=(1ll<<z);
        lazy[v]=st[v];
        return ;
    }
    push(v);
    ll tm=(tl+tr)/2;
    update(2*v,tl,tm,l,min(tm,r),z);
    update(2*v+1,tm+1,tr,max(tm+1,l),r,z);
    st[v]=(st[2*v]|st[2*v+1]);
}
ll query(ll v,ll tl,ll tr,ll l,ll r)
{
    // debug(v);
    // debug(l);
    // debug(r);
    if(l>r)
        return 0;
    if(tl==l&&tr==r)
    {
        return st[v];
    }
    push(v);
    ll tm=(tl+tr)/2;
    ll ff= ((query(2*v,tl,tm,l,min(tm,r)))|(query(2*v+1,tm+1,tr,max(l,tm+1),r)));
    return ff;
}
int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(9);
    #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    rep(i,n)
    {
        cin>>col[i+1];
        col[i+1]--;
    }
    rep(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs0(1,1);
    for(ll i=1;i<=n;i++)
    {
        ll z=tin[i];
        c[z]=col[i];
    }
    build(1,0,tim);
    // for(ll i=1;i<=n;i++)
    // {
    //     debug(tin[i]);
    //     debug(tout[i]);
    // }
    // cout<<st[1];
    while(m--)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll x, y;
            cin>>x>>y;
            update(1,0,tim,tin[x],tout[x],y-1);
        }
        else
        {
            ll x;
            cin>>x;
            ll z=(query(1,0,tim,tin[x],tout[x]));
            // debug(z);
            ll zz=0;
            while(z!=0)
            {
                if(z%2==1)
                {
                    zz++;
                }
                z/=2;
            }
            cout<<zz<<endl;
        }
    }
    // debug(tim);


    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}