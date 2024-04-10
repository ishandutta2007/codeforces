 #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;
#define ll int
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
#define INF 1000000000
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000003
#define dec decr
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
ll st[800080][32];
ll ar[200008][7];
ll n,k;
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        ll kk=tl;
        for(ll i=0;i<(1<<k);i++)
        {
            ll x=0;
            rep(j,k)
            {
                if((1<<j)&i)
                {
                    x+=ar[tl][j];
                }
                else
                {
                    x-=ar[tl][j];
                }
            }
            st[v][i]=x;
            // debug(x);
        }
        return ;
    }
    ll tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    for(ll i=0;i<(1<<k);i++)
    {
        st[v][i]=min(st[2*v][i],st[2*v+1][i]);
    }   
}
void update(ll v,ll tl,ll tr,ll z)
{
    if(tr==tl)
    {
        for(ll i=0;i<(1<<k);i++)
        {
            ll x=0;
            rep(j,k)
            {
                if((1<<j)&i)
                {
                    x+=ar[tl][j];
                }
                else
                {
                    x-=ar[tl][j];
                }
            }
            st[v][i]=x;
        }
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(z<=tm)
        {
            update(2*v,tl,tm,z);
        }
        else
            update(2*v+1,tm+1,tr,z);
        for(ll i=0;i<(1<<k);i++)
        {
            st[v][i]=min(st[2*v][i],st[2*v+1][i]);
        } 
    }
}
ll query(ll v,ll l,ll r, ll tl,ll tr,ll i)
{
    if(l>r)
    {
        return INF;
    }
    if(l==tl&&r==tr)
    {
        return st[v][i];
    }
    else
    {
        ll tm=(tl+tr)/2;
        return min(query(2*v,l,min(tm,r),tl,tm,i),query(2*v+1,max(tm+1,l),r,tm+1,tr,i));
    }
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
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        rep(j,k)
        {
            cin>>ar[i][j];
        }
    }
    ll q;
    cin>>q;
    build(1,0,n-1);
    rep(ixx,q)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll i;
            cin>>i;
            i--;
            rep(j,k)
            {

                cin>>ar[i][j];
            }
            update(1,0,n-1,i);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            l--;r--;
            ll ans=0;
            // debug(l);
            // debug(r);
            for(ll i=0;i<(1<<k);i++)
            {
                ll a1=query(1,l,r,0,n-1,i);
                ll b1=i^((1<<k)-1);
                b1=query(1,l,r,0,n-1,b1);
                ans=max(ans,abs(a1+b1));
            }
            cout<<ans<<endl;
        }
    }




    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}