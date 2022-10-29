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
ll ff[(1<<9)+10];
ll piz[(1<<9)+10];
ll club[(1<<9)+10];
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
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        ll x;
        cin>>x;
        ll mask=0;
        rep(j,x)
        {
            ll z;
            cin>>z;
            z--;
            mask=(mask|(1<<z));
        }
        ff[mask]++;
    }
    rep(i,(1<<9)+10)
    {
        piz[i]=INF;
        club[i]=INF;
    }
    ll id[5000]={0};
    ll m1=INF,m2=INF,i1=-1,i2=-1;
    rep(i,m)
    {
        ll c=0;
        cin>>c;
        // debug(c);
        ll x;
        cin>>x;
        ll mask=0;
        rep(j,x)
        {
            ll z;
            cin>>z;
            z--;
            mask=(mask|(1<<z));
        }
        if(piz[mask]>c)
        {
            piz[mask]=c;
            // debug(mask);
            id[mask]=i+1;
        }
        if(c<m1)
        {
            m2=m1;
            i2=i1;
            m1=c;
            i1=i+1;
        }
        else if(c<m2)
        {
            m2=c;
            i2=i+1;
        }
    }
    vector<ll>v[5000];
    for(ll i=1;i<(1<<9);i++)
    {
        for(ll j=1;j<(1<<9);j++)
        {
            if(club[(i|j)]>piz[i]+piz[j]&&i!=j)
            {
                club[(i|j)]=piz[i]+piz[j];
                // debug((i|j));
                v[(i|j)].clear();
                v[(i|j)].pb(id[i]);
                v[(i|j)].pb(id[j]);
            }
        }
    }
    ll mx=0;ll cost=INF;ll ans=-1;
    for(ll i=1;i<(1<<9);i++)
    {
        ll z=0;
        // ll c=0;
        // debug(club[i]);
        // if(club[i]!=INF)
        // {
        //     debug
        // }
        if(club[i]!=INF)
        {
            for(ll j=1;j<(1<<9);j++)
            {
                if((i&j)==j)
                {
                    z+=ff[j];
                }
            }
        }
        if(mx<z&&club[i]!=INF)
        {
            mx=z;
            cost=club[i];
            ans=i;
        }
        if(mx==z&&club[i]!=INF&&cost>club[i])
        {
            cost=club[i];
            ans=i;
        }
        // debug(z)
    }
    // cout<<mx;
    // debug(ans);
    if(ans!=-1)
    {
        cout<<v[ans][0]<<' '<<v[ans][1];
    }
    else
    {
        cout<<i1<<' '<<i2;

    }


    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}