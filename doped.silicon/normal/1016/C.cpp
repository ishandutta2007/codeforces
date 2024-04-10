#include <bits/stdc++.h>
 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef gp_hash_table<long long, long long> umap;
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
#define ll long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y0 yyyyyy0
#define y1 yyyyyy1
#define sot(bello) bello.begin(),bello.end()
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
#define INF 1000000000000000
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define dec decr
//END OF COMPETITVE PROGRAMMING TEMPLATE
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
        if (y & 1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}
void computeLPSArray(string pat, ll M, ll* lps) 
{ 
    // length of the previous longest prefix suffix 
    ll len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    ll i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1];
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
ll a[300007];
ll b[300007];
ll mat[300007][2];
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        cout<<setprecision(11);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n;
        cin>>n;
        rep(i,n)
        {
            cin>>mat[i][0];
        }
        rep(i,n)
        {
            cin>>mat[i][1];
        }
        ll t=2;
        ll x=0;
        ll z[n+5]={0};
        for(ll i=n-1;i>=0;i--)
        {
            
            if(i%2==1)
            {
                b[i]=mat[i][0]*(t-1)+mat[i+1][0]*(t-3)+x+b[i+1];
                // debug("adsf");
                a[i]=x+a[i+1];
            }
            else
            {
            b[i]=x+b[i+1];
            // debug(b[i]);
            a[i]=mat[i][1]*(t-1)+mat[i+1][1]*(t-3)+x+a[i+1];
            }
            x+=mat[i][0]+mat[i][1];
            z[i]=x;
            t+=2;
            // debug(i);
            // debug(a[i]);
            // debug(b[i]);
        }
        ll ans=0;
        ll now=0;
        ll x1=0,y1=0;
        rep(i,2*n)
        {
            if((x1==0&&y1==0||x1==1&&y1==1))
            {
                // cout<<'c';
                ll k=a[i/2]+now+i*z[i/2];
                // debug(k);
                
                if(x1)
                {
                    k=a[i/2]+now+i*(z[i/2]-mat[i/2][1]);
                    // debug(i*(z[i/2]-mat[i/2][1]));
                    // debug(a[i/2]);
                    x1=0;
                    y1=0;
                }
                else
                {
                    y1=1;
                }
                now+=(i)*mat[i/2][0];
                ans=max(ans,k);
            }
            else
            {
                ll k=0;
                if(x1==0)
                {
                     k=b[i/2]+now+i*(z[i/2]-mat[i/2][0]);
                     // debug(k);
                    x1=1;
                    y1=0;
                }
                else
                 {
                   k=b[i/2]+now+i*(z[i/2]);  
                   // debug(k);
                    y1=1;
                    x1=1;
                 }   
                 now+=(i)*mat[i/2][1];
                ans=max(ans,k);
            }
            // cout<<x1<<" "<<y1<<endl;
            // debug(ans);
        }
        cout<<ans<<endl;
        return 0;
}