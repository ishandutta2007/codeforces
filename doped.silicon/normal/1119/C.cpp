#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second


typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

#define PI 3.1415926535897932385
#define INF 1000000000000000
#define EPS 1e-7
#define MAXN 100000
#define MOD 998244353  //1000000007
#define dec decr
#define endl '\n'
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
ll mat1[505][505];
ll mat2[505][505];
ll flip[505][505];
signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(11);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n,m;
        cin>>n>>m;
        rep(i,n)
        {
            rep(j,m)
            {
                cin>>mat1[i][j];
            }
        }
        rep(i,n)
        {
            rep(j,m)
            {
                cin>>mat2[i][j];
            }
        }
        rep(i,n)
        {
            rep(j,m)
            {
                if(mat1[i][j]!=mat2[i][j])
                {
                    flip[i][j]=1;
                }
            }
        }
        ll last=-1;
        rep(i,n-1)
        {
            rep(j,m)
            {
                if(last==-1&&flip[i][j])
                {
                    last=j;
                }
                else if(flip[i][j])
                {
                    flip[i+1][j]=flip[i+1][j]^1;
                    flip[i+1][last]=flip[i+1][last]^1;
                    last=-1;
                }
            }
            if(last!=-1)
            {
                cout<<"No";
                return 0;
            }
        }
        ll f=1;
        rep(j,m)
        {
            if(flip[n-1][j]!=0)
            {
                f=0;
                cout<<"No";
                return 0;
            }
        }
                cout<<"Yes";
        

        

        return 0;













}