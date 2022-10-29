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
#define INF 1000000000000000000
#define EPS 1e-7
#define MAXN 100000
#define MOD 998244353ll
#define dec decr
//END OF COMPETITVE PROGRAMMING TEMPLATE
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
    ld t;
    cin>>n>>t;
    ld ar[n];
    rep(i,n)
    {
        cin>>ar[i];
    }
    vector<pair<ld,ld>>v1,v2;
    ld ans=0;
    ld p1=0,p2=0;
    rep(i,n)
    {
        ld x;
        cin>>x;
        // debug(x);
        // debug(t);
        if(x>t)
        {
            v1.pb(mp(x-t,ar[i]));
            p1+=(x-t)*ar[i];
        }
        else if(x<t)
        {
            v2.pb(mp(t-x,ar[i]));
            p2+=-(x-t)*ar[i];
        }
        ans+=ar[i];
        // debug(p1);
        // debug(p2);
        // cout<<endl;
    }
    // debug(p1);
    // debug(p2);
    // debug(ans);
    sort(all(v1));
    sort(all(v2));
    reverse(all(v2));
    reverse(all(v1));
    if(p1>p2)
    {
        ld d=p1-p2;
        ll f=0;
        for(auto x:v1)
        {
            if(f==0)
            {
                ld z=x.ff*x.ss;
                if(z<d)
                {
                    ans-=x.ss;
                    d-=x.ss*x.ff;
                }
                else
                {
                    ld xx=d*1.0/x.ff;
                    ans-=xx;
                    d=0;
                    f=1;
                    p1=(x.ss-xx)*x.ff;
                }
            }
            else
            {
                p1+=x.ss*x.ff;
            }
        }
    }
    else
    {
        ld d=p1-p2;
        d=-d;
        // debug(d);
        ll f=0;
        for(auto x:v2)
        {
            if(f)
            {
                p2+=(x.ss*x.ff);
            }
            if(f==0)
            {
                ld z=x.ff*x.ss;
                if(z<d)
                {
                    ans-=x.ss;
                    d-=x.ss*x.ff;
                }
                else
                {
                    ld xx=d/x.ff;
                    // debug(xx);
                    // debug(xx*x.ff);
                    ans-=xx;
                    d=0;
                    f=1;
                    p2=(x.ss-xx)*x.ff;
                    // debug(p2);
                }
            }
            
        }
    }
    cout<<ans<<endl;
    // debug(p1);
    // debug(p2);
    if((abs(p1-p2))>=EPS*10)
    {
        cout<<"1";
    }
    


    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}