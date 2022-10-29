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
char mat[1010][1010];
ll mark[1010][1010];
ll ans[1010][1010];
bool poor=false;
ll dfs(ll n,ll m)
{
    // debug(n);
    // debug(m);
    //debug(mat[n][m]);
    if(mark[n][m]==1&&ans[n][m]==-1)
    {
        poor=true;
        ans[n][m]=0;
        return 0;
    }
    if(mark[n][m]==1)
    {

        return ans[n][m];
    }
    mark[n][m]=1;
    if(mat[n][m]=='A')
    {
        ll x1=0,x2=0,x3=0,x4=0;
        if(n!=0&&mat[n-1][m]=='D')
        {
            x1=dfs(n-1,m);
        }
        if(m!=0&&mat[n][m-1]=='D')
        {
            x2=dfs(n,m-1);
        }
        if(mat[n+1][m]=='D')
        {
            x3=dfs(n+1,m);
        }
        if(mat[n][m+1]=='D')
        {
            x4=dfs(n,m+1);
        }
        ans[n][m]= max(max(x3,x4),max(x1,x2))+1;
        return ans[n][m];
    }
    if(mat[n][m]=='D')
    {
        // debug(n);
        // debug(m);
        ll x1=0,x2=0,x3=0,x4=0;
        if(n!=0&&mat[n-1][m]=='I')
        {
            x1=dfs(n-1,m);
        }
        if(m!=0&&mat[n][m-1]=='I')
        {
            x2=dfs(n,m-1);
        }
        if(mat[n+1][m]=='I')
        {
            x3=dfs(n+1,m);
        }
        if(mat[n][m+1]=='I')
        {
            x4=dfs(n,m+1);
        }
        ans[n][m]= max(max(x3,x4),max(x1,x2));
        return ans[n][m];
    }
    if(mat[n][m]=='I')
    {
        ll x1=0,x2=0,x3=0,x4=0;
        if(n!=0&&mat[n-1][m]=='M')
        {
            x1=dfs(n-1,m);
        }
        if(m!=0&&mat[n][m-1]=='M')
        {
            x2=dfs(n,m-1);
        }
        if(mat[n+1][m]=='M')
        {
            x3=dfs(n+1,m);
        }
        if(mat[n][m+1]=='M')
        {
            x4=dfs(n,m+1);
        }
        ans[n][m]= max(max(x3,x4),max(x1,x2));
        return ans[n][m];
    }
    if(mat[n][m]=='M')
    {
        ll x1=0,x2=0,x3=0,x4=0;
        if(n!=0&&mat[n-1][m]=='A')
        {
            x1=dfs(n-1,m);
        }
        if(m!=0&&mat[n][m-1]=='A')
        {
            x2=dfs(n,m-1);
        }
        if(mat[n+1][m]=='A')
        {
            x3=dfs(n+1,m);
        }
        if(mat[n][m+1]=='A')
        {
            x4=dfs(n,m+1);
        }
        ans[n][m]= max(max(x3,x4),max(x1,x2));
        return ans[n][m];
    }
    return 0;
}
int main () 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    rep(i,1010)
    {
        rep(j,1010)
        {
            ans[i][j]=-1;
        }
    }
    ll an=0;
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        rep(j,m)
        {
            cin>>mat[i][j];
        }
    }
    rep(i,n)
    {
        rep(j,m)
        {
            if(mat[i][j]=='D')
            {
                 // debug(i);
                 // debug(j);
                ll x=dfs(i,j);
                an=max(an,x);
            }
        }
    }
    if(poor)
    {
        cout<<"Poor Inna!"<<endl;
    }
    else if(!an)
    {
        cout<<"Poor Dima!"<<endl;
    }
    else
    {
        cout<<an<<endl;
    }
    return 0;
}