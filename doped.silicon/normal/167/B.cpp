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
double dp[205][205][201];
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
             ll n,l,k;
            cin>>n>>l>>k;
            ll p[n];
            ll c[n];
            
            rep(i,n)
            {
                cin>>p[i];
            }
            rep(i,n)
            {
                ll x;
                cin>>x;
                c[i]=x+1;
            }
            dp[0][0][k]=1;
             for(ll i=0;i<n;i++)
             {
                for(ll j=0;j<=i;j++)
                 {
                    for(ll kk=k;kk<=200;kk++)
                    {
                        if(kk+c[i]<=200)
                        {
                        dp[i+1][j+1][kk+c[i]]+=dp[i][j][kk]*(p[i]*1.0)/100.0;
                        
                        }
                        else
                            dp[i+1][j+1][200]+=dp[i][j][kk]*(p[i]*1.0)/100.0;
                        dp[i+1][j][kk]+=dp[i][j][kk]*(1.0-(p[i]*1.0)/100.0);
                    }
                }
            }
            double ans=0;
            for(ll j=l;j<=n;j++)
            {
                for(ll kk=max(k,j);kk<=200;kk++)
                {
                    ans+=dp[n][j][kk];
                }
            }
            //ans=1.04423958403;
            cout<<setprecision(8)<<ans;
            return 0;
}