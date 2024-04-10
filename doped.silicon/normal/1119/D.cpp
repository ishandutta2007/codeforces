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
        vector<ll>v;
        rep(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        sort(all(v));
        ll ar[n]={0};
        ar[0]=1000000000000000001ll;
        rep(i,n-1)
        {
            ar[i+1]=v[i+1]-v[i];
        }
        sort(ar,ar+n);
        ll q;
        ll pre[n+1]={0};
        rep(i,n)
        {
            // debug(ar[i]);
            pre[i+1]+=pre[i]+ar[i];
            // debug(pre[i+1]);
        }
        cin>>q;
        rep(dafds,q)
        {
            ll a,b;
            cin>>a>>b;
            ll x=b-a+1;
            ll l=0,r=n-1;
            ll mid;
            ll ans=-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(ar[mid]>x)
                {
                    r=mid-1;
                }
                else
                {
                    ans=mid;
                    l=mid+1;
                }
            }
            // debug(ans);
            ll z=pre[ans+1]+x*(n-1-ans);
            cout<<z<<" ";
        }

        

        return 0;













}