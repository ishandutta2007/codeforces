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
ll pos[1010][1010];
int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll n,m;
            cin>>n>>m;
            ll ar[n+1][m+1];

            rep(i,n)
            {
                rep(j,m)
                {
                    char c;
                    cin>>c;
                    if(c=='#')
                    {
                        ar[i+1][j+1]=1;
                    }
                    else
                    {
                        ar[i+1][j+1]=0;
                    }
                }
            }
            for(ll i=2;i<=n-1;i++)
            {
                for(ll j=2;j<=m-1;j++)
                {
                    if(ar[i-1][j-1]==1&&ar[i+1][j+1]==1&&ar[i+1][j-1]==1&&ar[i-1][j+1]==1&&ar[i-1][j]==1&&ar[i+1][j]==1&&ar[i][j+1]==1&&ar[i][j-1]==1)
                    {
                        pos[i-1][j-1]=1;pos[i+1][j+1]=1;pos[i+1][j-1]=1;pos[i-1][j+1]=1;pos[i-1][j]=1;pos[i+1][j]=1;pos[i][j+1]=1;pos[i][j-1]=1;
                    }
                }
            }
            bool x=true;
            for(ll i=1;i<=n;i++)
            {
                for(ll j=1;j<=m;j++)
                {
                    // if(ar[i-1][j-1]==1&&ar[i+1][j+1]==1&&ar[i+1][j-1]==1&&ar[i-1][j+1]==1&&ar[i-1][j]==1&&ar[i+1][j]==1&&ar[i][j+1]==1&&ar[i][j-1]==1)
                    // {
                    //     pos[i-1][j-1]=1;pos[i+1][j+1]=1;pos[i+1][j-1]=1;pos[i-1][j+1]=1;pos[i-1][j]=1;pos[i+1][j]=1;pos[i][j+1]=1;pos[i][j-1]=1;
                    // }
                    if(ar[i][j]==1&&pos[i][j]!=1)
                    {
                        x=false;
                    }
                }
            }
            if(x)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            return 0;
}