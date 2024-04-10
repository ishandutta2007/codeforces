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
#define MOD 1000000007
#define dec decr
#define INT_SIZE 32 
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
        if (y & 1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}
vector<ll>v[200006];
vector<ll>ep;
ll bt[200006];
ll et[200006];
ll mark[200006];
ll t=0;
ll fw1[200006];
ll fw2[200006];
ll fin[200006];
ll lvl[200006];
ll n;
void update1(ll x,ll v)
{
    // debug(x);
    // debug(v);
    for(;x<=n;x+=x&-x)
    {
        // debug(x);
        fw1[x]+=v;
    }
}
void update2(ll x,ll v)
{
    for(;x<=n;x+=x&-x)
    {
        fw2[x]+=v;
    }
}
ll get1(ll x)
{
    ll ans=0;
    for(;x>=1;x-=x&-x)
    {
        ans+=fw1[x];
    }
    return ans;
}
ll get2(ll x)
{
    ll ans=0;
    for(;x>=1;x-=x&-x)
    {
        ans+=fw2[x];
    }
    return ans;
}
void dfstime(ll x)
{
    t++;
    ep.pb(x);
    mark[x]=1;
    bt[x]=t;
    for(auto z:v[x])
    {
        if(mark[z]==0)
        {
            dfstime(z);
        }
    }
    et[x]=t;
}
int main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<fixed;
        cout<<setprecision(9);
         #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n,m;
        cin>>n>>m;
        ll ans[m+1]={0};
        ll t[9]={0};
        vector<pair<ll,ll>>v;
        rep(i,m)
        {
            ll x,y;
            cin>>x>>y;
            v.pb(mp(x,y));
        }
        vector<pair<ll,ll>>v1[2*n+1];
        rep(i,m)
        {
            ll a=v[i].ff;
            ll b=v[i].ss;
            v1[a].pb(mp(b,i));
        }
        rep(i,n+1)
        {
            ll a=i;
            ll f=0;
            if(v1[a].size()>=1)
            {
            sort(all(v1[a]));
                f=v1[a][0].ss;
            // debug(f);
            }
            if(v1[a].size()>1)
            {
                ans[f]+=1;
                f=v1[a][v1[a].size()-1].ss;
                ans[f]+=1;
            }
            ll xx=v1[a].size();
            for(ll j=1;j<xx-1;j++)
            {
                f=v1[a][j].ss;
                ans[f]+=2;
            }
            v1[a].clear();
        }
        rep(i,m)
        {
            ll b=v[i].ff;
            ll a=v[i].ss;
            v1[a].pb(mp(b,i));
        }
        rep(i,n+1)
        {
            ll a=i;
            sort(all(v1[a]));
            ll f;
            if(v1[a].size()>=1)
                f=v1[a][0].ss;
            if(v1[a].size()>1)
            {
                // debug(f);
                // debug(a);
                ans[f]+=1;
                f=v1[a][v1[a].size()-1].ss;
                ans[f]+=1;
            }
            ll xx=v1[a].size();
                for(ll j=1;j<xx-1;j++)
                {
                    f=v1[a][j].ss;
                    ans[f]+=2;
                }
            v1[a].clear();
        }
        rep(i,m)
        {
            ll b=v[i].ff;
            ll a=v[i].ss;
            v1[a-b+n].pb(mp(b,i));
        }
        rep(i,2*n+1)
        {
            ll a=i;
            sort(all(v1[a]));
            ll f;
            if(v1[a].size()>=1)
                f=v1[a][0].ss;
            if(v1[a].size()>1)
            {
                ans[f]+=1;
                f=v1[a][v1[a].size()-1].ss;
                ans[f]+=1;
            }
            ll xx=v1[a].size();
                for(ll j=1;j<xx-1;j++)
                {
                    f=v1[a][j].ss;
                    ans[f]+=2;
                }
            v1[a].clear();
        }
        rep(i,m)
        {
            ll b=v[i].ff;
            ll a=v[i].ss;
            v1[a+b].pb(mp(b,i));
        }
        rep(i,2*n+1)
        {
            ll a=i;
            sort(all(v1[a]));
            ll f;
            if(v1[a].size()>=1)
                f=v1[a][0].ss;
            if(v1[a].size()>1)
            {
                ans[f]+=1;
                f=v1[a][v1[a].size()-1].ss;
                ans[f]+=1;
            }
            ll xx=v1[a].size();
                for(ll j=1;j<xx-1;j++)
                {
                    f=v1[a][j].ss;
                    ans[f]+=2;
                }
            v1[a].clear();
        }
        rep(i,m)
        {
            t[ans[i]]+=1;
        }
        rep(i,9)
        {
            cout<<t[i]<<" ";
        }




            return 0;
}