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
ll find(char a)
{
    if(a>='a'&&a<='z')
    {
        return a-'a';
    }
    else 
        return a-'A'+26;
}
int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    cout<<setprecision(11);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll ar[53]={0};
            ll f[100007]={0};
            ll in[100007]={0};
            ll dp[100007]={0};
            string s;
            cin>>s;
            rep(i, s.length())
            {
                ar[find(s[i])]++;
            }
            f[0]=1;
            ll n=s.length();
            for(ll i=1;i<=n;i++)
            {
                f[i]=(f[i-1]*i)%MOD;
            }
            in[n]=modexp(f[n],MOD-2,MOD);
            for(ll i=n-1;i>=0;i--)
            {
                in[i]=(in[i+1]*(i+1))%MOD;
            }
            // debug(f[n/2]);
            ll cons=(f[n/2]*f[n/2])%MOD;
            rep(i,52)
            {
            	if(ar[i]!=0)
                cons=(cons*in[ar[i]])%MOD;
            }
            dp[0]=1;
            rep(i,52)
            {
                if(ar[i]!=0)
                {
                	// debug(i);
                    for(ll j=n;j>=ar[i];j--)
                    {
                        dp[j]=(dp[j]+dp[j-ar[i]]);
                        // debug(dp[j]);
                        // debug(j);
                        if(dp[j]>=MOD)
                        {
                            dp[j]-=MOD;
                        }
                    }
                }
            }
            ll ans[52][52];
            rep(i,52)
            {
                ans[i][i]=(cons*dp[n/2])%MOD;
            }
            // debug(cons);
            // debug(dp[n/2]);
            rep(i,52)
            {
                if(ar[i]==0)
                    continue;
                for(ll j=ar[i];j<=n;j++)
                {
                        dp[j]=(dp[j]-dp[j-ar[i]]);
                        if(dp[j]<0)
                        {
                            dp[j]+=MOD;
                        }
                }
                for(ll j=i+1;j<52;j++)
                {
                    if(ar[j]==0)
                        continue;
                    for(ll k=ar[j];k<=n;k++)
                    {
                            dp[k]=(dp[k]-dp[k-ar[j]]);
                            if(dp[k]<0)
                            {
                                dp[k]+=MOD;
                            }
                    }
                    ans[i][j]=(cons*2*dp[n/2])%MOD;
                    ans[j][i]=ans[i][j];
                    for(ll k=n;k>=ar[j];k--)
                    {
                            dp[k]=(dp[k]+dp[k-ar[j]]);
                            if(dp[k]>=MOD)
                            {
                                dp[k]-=MOD;
                            }
                    }
                }
                for(ll j=n;j>=ar[i];j--)
                {
                        dp[j]=(dp[j]+dp[j-ar[i]]);
                        if(dp[j]>=MOD)
                        {
                            dp[j]-=MOD;
                        }
                }
            }
            ll q;
            cin>>q;
            rep(i,q)
            {
                ll x,y;
                cin>>x>>y;
                cout<<ans[find(s[x-1])][find(s[y-1])]<<endl;
            }
            return 0;
}