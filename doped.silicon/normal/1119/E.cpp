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
        ll n;
        cin>>n;
        ll ar[n];
        ll ans=0;
        rep(i,n)
        {
            cin>>ar[i];
        }
        ll x=0;
        ll ext=0;
        ll oans=0;
        rep(i,n)
        {
            oans=ans;
            ll d=ar[i]/2;
            ll z=min(d,ext);
            ans+=z;
            ar[i]-=2*z;
            ext-=z;
            z=ar[i]/3;
            ans+=z;
            ar[i]-=z*3;
            ext+=ar[i];

        }
        cout<<ans;

        

        return 0;













}