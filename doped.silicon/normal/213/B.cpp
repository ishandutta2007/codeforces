#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define debug(x) cout<<#x<<": "<<x<<endl
#define dbug(x,y) cout<<x<<" "<<y<<endl

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
ll dp[101][10];
int main () 
{

    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
            ll n;
            cin>>n;
            ll a[10];
            ll ncr[n+1][n+1];
            rep(i,n+1)
            {
                rep(j,n+1)
                    ncr[i][j]=1;
            }
            
			
            for(ll i=2;i<=n;i++)
            {
                for(ll j=1;j<i;j++)
                {
                    ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
                    if(ncr[i][j]>MOD)
                        ncr[i][j]-=MOD;
                }
            }
            //debug("hfdksjh");
            rep(i,10)
            {
                cin>>a[i];
            }
            for(ll i=a[9];i<=n;i++)
                dp[i][9]=1;
            for(ll i=8;i>=1;i--)
            {
                for(ll j=0;j<=n;j++)
                {
                    for(ll k=a[i];k<=n;k++)
                    {
                        if(j-k>=0)
                        {
                        // debug(dp[j][i]);
                        // debug(ncr[j][j-k]);
                        dp[j][i]=(dp[j][i]+dp[j-k][i+1]*ncr[j][j-k])%MOD;
                        //debug(dp[j-k][i+1]);
                        // dbug(j,i);
                        // debug(dp[j][i]);
                        }
                    }
                }
            }
            for(ll j=0;j<=n;j++)
            {
                for(ll k=a[0];k<=n;k++)
                {
                	//debug(dp[j][0]);
                    if(j-k>0)
                        dp[j][0]=(dp[j][0]+dp[j-k][1]*ncr[j-1][j-1-k])%MOD;
                    //debug(dp[j][0]);
                }
            }
            ll ans=0;
            for(ll i=1;i<=n;i++)
            {
                ans=(ans+dp[i][0])%MOD;
            }
            cout<<ans;
            return 0;
}