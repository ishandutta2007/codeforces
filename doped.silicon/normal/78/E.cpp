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

ll tin[15][15];
ll cap[15][15];
ll sci[15][15];
ll mat[15][15];
ll mark[15][15];
ll dp[65][12][12][12][12];
vector<ll>adj[215];
ll capacity[215][215];


int bfs(int s, int t, vector<int>& parent) {
    rep(i,215)
    {
        parent[i]=-1;
    }
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        // debug(cur);
        // debug(flow);
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow() {
    ll s=103,t=104;
    int flow = 0;
    vector<int> parent(215);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        // debug(new_flow);
        // break;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
ll n;
bool check(ll k,ll i,ll j,ll x,ll y)
{
    if(x<0||y<0||x>n-1||y>n-1)
        return 0;
    else
        return dp[k-1][i][j][x][y]&&(mat[x][y]==0)&&(tin[x][y]>k-1);
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
    ll t;
    cin>>n>>t;
    ll x1=-1,y1=-1;
    rep(i,n)
    {
        rep(j,n)
        {
            char c;
            cin>>c;
            if(c=='Y')
            {
                mat[i][j]=1;
            }
            else if(c=='Z')
            {
                mat[i][j]=2;
                x1=i;y1=j;
            }
            else
            {
                sci[i][j]=c-'0';
            }
        }
    }
    rep(i,n)
    {
        rep(j,n)
        {
            char c;
            cin>>c;
            if(c=='Y')
            {
                mat[i][j]=1;
            }
            else if(c=='Z')
            {
                mat[i][j]=2;
                x1=i;y1=j;
            }
            else
            {
                cap[i][j]=c-'0';
            }
        }
    }
    rep(i,n)
    {
        rep(j,n)
        {
            tin[i][j]=INF;
        }
    }
    queue<pair<ll,ll>>q;
    q.push(mp(x1,y1));
    tin[x1][y1]=0;
    // debug(x1);
    while(!q.empty())
    {
        int x=q.front().ff;
        int y=q.front().ss;
        q.pop();
        if(x-1>=0&&tin[x][y]+1<tin[x-1][y]&&mat[x-1][y]==0)
        {
            tin[x-1][y]=tin[x][y]+1;
            q.push(mp(x-1,y));
        }
        if(y-1>=0&&tin[x][y]+1<tin[x][y-1]&&mat[x][y-1]==0)
        {
            tin[x][y-1]=tin[x][y]+1;
            q.push(mp(x,y-1));
        }
        if(x+1<n&&tin[x][y]+1<tin[x+1][y]&&mat[x+1][y]==0)
        {
                tin[x+1][y]=tin[x][y]+1;
                q.push(mp(x+1,y));
        }
        if(y+1<n&&tin[x][y]+1<tin[x][y+1]&&mat[x][y+1]==0)
        {
            tin[x][y+1]=tin[x][y]+1;
            q.push(mp(x,y+1));
        }
    }    
    rep(i,n)
    {
        rep(j,n)
        {
            dp[0][i][j][i][j]=1;
        }
    }
    for(ll k=1;k<=t;k++)
    rep(i,n)
    {
        rep(j,n)
        {
            rep(i1,n)
            {
                rep(j1,n)
                {
                    dp[k][i][j][i1][j1]=dp[k-1][i][j][i1][j1];
                    if(tin[i1][j1]>=k)
                    {
                        ll x=i1;
                        ll y=j1;
                        if(check(k,i,j,x-1,y)||check(k,i,j,x,y-1)||check(k,i,j,x+1,y)||check(k,i,j,x,y+1))
                        {
                            if(mat[i1][j1]==0)
                            {
                                dp[k][i][j][i1][j1]=1;
                            }
                                
                        }   
                    }
                }
            }
        }
    }

    rep(i,n)
    {
        rep(j,n)
        {
            rep(i1,n)
            {
                rep(j1,n)
                {
                    if(dp[t][i][j][i1][j1])
                    {
                        if(cap[i1][j1]&&sci[i][j])
                        {
                            capacity[i*10+j][i1*10+j1+105]=min(cap[i1][j1],sci[i][j]);
                            // if(i1!=i||j1!=j)
                            {
                                adj[i*10+j].pb(i1*10+j1+105);
                                adj[i1*10+j1+105].pb(i*10+j);
                            }
                        }
                    }
                }
            }
        }
    }
    // debug(n);
    rep(i,n)
    {
        rep(j,n)
        {
            if(sci[i][j])
            {
                adj[103].pb(i*10+j);
                adj[10*i+j].pb(103);
                capacity[103][i*10+j]=sci[i][j];
            }
            if(cap[i][j])
            {
                adj[104].pb(i*10+j+105);
                adj[10*i+j+105].pb(104);
                capacity[i*10+j+105][104]=cap[i][j];   
            }
        }
    }
    // for(auto x:adj[103])
    // {
    //     cout<<x<<endl;
    //     for(auto z:adj[x])
    //     {
    //         cout<<z<<endl;
    //     }
    //     cout<<endl;
    // }
    ll zz=maxflow();
    // if(zz!=89)
    cout<<zz;
    // else
        // cout<<zz-1;

    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}