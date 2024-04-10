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
#define INF 1000000000000000000ll
#define EPS 1e-7
#define MAXN 100000
#define MOD 998244353 
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
vector<ll>adj[201];
ll capacity[201][201],cost[201][201];
ll p[201];
ll d[210];
void shortest_paths() 
{
     rep(i,210)
    {
        d[i]=INF;
    }
    d[0] = 0;
    vector<int> m(201, 2);
    deque<int> q;
    q.push_back(0);
    rep(i,201)
    {
        p[i]=-1;
    }

    while (!q.empty()) {
        int u = q.front();
        // debug(u);
        q.pop_front();
        m[u] = 0;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (m[v] == 2) {
                    m[v] = 1;
                    q.push_back(v);
                } else if (m[v] == 0) {
                    m[v] = 1;
                    q.push_front(v);
                }
            }
        }
    }
}
ll k;
void mcmf()
{
    ll flow=0;
    ll cos=0;
    while(flow<k)
    {
        // debug("Dsa");
        shortest_paths();
        // debug(d[200]);
        if(d[200]==INF)
        {
            break;
        }
        // break;
        ll f=k-flow;
        ll zz=200;
        // debug(f);
        while(zz!=0)
        {
            f=min(f,capacity[p[zz]][zz]);
            // debug(zz);
            zz=p[zz];
        }
        zz=200;
        // debug(f);
        // debug(cos);
        while(zz!=0)
        {
            cos+=cost[p[zz]][zz]*f;
            capacity[p[zz]][zz]-=f;
            // debug(p[zz]);
            // debug(zz);
            // debug(capacity[p[zz]][zz]);
            capacity[zz][p[zz]]+=f;
            zz=p[zz];
        }
        flow+=f;
    }
    if(flow<k)
        cout<<"-1";
    else
    {
        cout<<cos;
    }
    // cout<<"ds";
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
   
    string t;cin>>t;
    ll n;
    cin>>n;
    string s[105];
    ll ar[105];
    k=t.length();
    rep(i,n)
    {
        cin>>s[i+1];
        cin>>ar[i+1];
    }
    for(ll i=1;i<=n;i++)
    {
        capacity[0][i]+=ar[i];
        // debug(capacity[0][i]);
        cost[0][i]=i;
        cost[i][0]=-i;
        adj[0].pb(i);
        adj[i].pb(0);
        rep(j,s[i].length())
        {
            ll z=s[i][j]-'a'+1;
            capacity[i][102+z]+=1;
            // debug(i);
            // debug(z);
            // debug(capacity[i][102+z]);
            adj[102+z].pb(i);
            adj[i].pb(102+z);
        }
    }
    rep(i,t.length())
    {
        ll z=t[i]-'a'+1;
        capacity[102+z][200]+=1;
        adj[102+z].pb(200);
            adj[200].pb(102+z);

    }
    // debug(k);
    mcmf();

    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}