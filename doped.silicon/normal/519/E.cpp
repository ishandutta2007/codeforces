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
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
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
#define MOD 1000000007
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
ll tim=1;
ll tin[100005];
ll tout[100005];
vector<ll>v[100005];
int up[100005][20];
int chi[100005];
ll dfs(ll x,ll p)
{
    tin[x]=tim++;
    up[x][0]=p;
    ll zz=0;
    for(ll i=1;i<=19;i++)
    {
        up[x][i]=up[up[x][i-1]][i-1];
    }
    for(auto z:v[x])
    {
        if(tin[z]==0)
        {
            zz+=dfs(z,x);
        }
    }
    chi[x]=zz;
    tout[x]=tim++;
    return zz+1;
}
ll n;
bool isan(ll x,ll y)
{
    return tin[x]<=tin[y]&&tout[y]<=tout[x];
}
ll lca(ll x,ll y)
{
    if(isan(x,y))return x;
    if(isan(y,x))return y;
    for(ll i=19;i>=0;i--)
    {
        if(!isan(up[x][i],y))
        {
            x=up[x][i];
        }
    }
    return up[x][0];
}
ll dis(ll x,ll y)
{
    if(x==y)
        return 0;
    ll ans=0;
    ll d=1<<19;
    for(ll i=19;i>=0;i--)
    {
        if(!isan(up[x][i],y))
        {
            x=up[x][i];
            ans+=d;
        }
        d/=2;
    }
    return ans+1;
}
ll findnode(ll x,ll d)
{
    ll z=0;
    while(d!=0)
    {
        if(d%2)
        {
            x=up[x][z];
        }
        d/=2;
        z++;
    }
    return x;
}
ll find(ll x,ll y)
{
    if(x==y)
    {
        return n;
    }
    ll lc=lca(x,y);
    ll d1=dis(x,lc);
    ll d2=dis(y,lc);
    if(x==2&&y==1)
    {
        // debug(lc);
        // debug(d1);
        // debug(d2);
        // debug(x);
    }
    if((d1+d2)%2==1)
        return 0;
    if(d1==d2)
    {
        // debug(findnode(x,d1));
        ll x1=chi[findnode(x,d1-1)]+1;
        ll x2=chi[findnode(y,d1-1)]+1;
        // ll x2
        return n-x1-x2;
    }
    ll k=(d1+d2)/2;
    if(d1>d2)
    {
        // debug(k);
        // debug(up[x][1]);
        ll a=findnode(x,k);
        // debug(a);
        ll b=findnode(x,k-1);
        a=chi[a];
        b=chi[b];
        return a-b;
    }
        ll a=findnode(y,k);
        ll b=findnode(y,k-1);
        a=chi[a];
        b=chi[b];
        return a-b;
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
    cin>>n;
    rep(i,n-1)
    {
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(0,0);
    ll q;
    cin>>q;
    rep(i,q)
    {
        ll x,y;
        cin>>x>>y;x--;y--;
        cout<<find(x,y)<<endl;
    }

    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}