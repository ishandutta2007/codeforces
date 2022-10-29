#include <bits/stdc++.h>

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
#define INF 1000111222
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
ll dp[200010][6]; 

ll a[200010];
ll n;
pair<ll,ll> bk(ll x);
pair<ll,ll> frw(ll x)
{
	//debug(x);
	if(dp[x][0]==1)
	{
		return mp(dp[x][2],dp[x][4]);
	}
	dp[x][0]=1;
	if(x+a[x]>n)
	{
		dp[x][2]=-2;
		dp[x][4]=a[x];
		return mp(-2,a[x]);
	}
	if(dp[x+a[x]][1]==1&&dp[x+a[x]][3]!=-2)
	{
		dp[x][2]=-1;
		return mp(-1,0);
	}
	else
	{
		//debug(x);
		pair<ll,ll> p;
		p=bk(x+a[x]);
		dp[x][2]=p.first;
		dp[x][4]=p.second+a[x];
		return mp(p.first,p.second+a[x]);
	}
}
pair<ll,ll> bk(ll x)
{
	//debug(x);
	if(dp[x][1]==1)
	{
		//debug(x);
		return mp(dp[x][3],dp[x][5]);
	}
	dp[x][1]=1;
	if(x-a[x]<=0)
	{
		//debug(x);
		dp[x][3]=-2;
		dp[x][5]=a[x];
		return mp(-2,a[x]);
	}
	if(dp[x-a[x]][0]==1&&dp[x-a[x]][2]!=-2)
	{
		//debug(x);
		dp[x][3]=-1;
		return mp(-1,0);
	}
	else
	{
		//debug(x);
		pair<ll,ll> p;
		p=frw(x-a[x]);
		dp[x][3]=p.first;
		dp[x][5]=p.second+a[x];
		return mp(p.first,p.second+a[x]);
	}
}
int main () 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ll n;
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][3]=-2;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][3]=-2;
    cin>>n;
    
    rep(i,n-1)
    {
    	cin>>a[i+2];
    }
    for(ll i=2;i<=n;i++)
    {
    	if(dp[i][1]!=1)
    	{
    		ll z=bk(i).first;
    		//cout<<z<<endl;
    	}
    }
    for(ll i=2;i<=n;i++)
    {
    	if(dp[i][3]==-2)
    	cout<<i-1+dp[i][5]<<endl;
    	else
    	{
    		cout<<"-1"<<endl;
    	}
    }
    return 0;
}