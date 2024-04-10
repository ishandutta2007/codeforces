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
#define MOD 998244353
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
            ll a[n+1];
            ll b[n+1]={0};
            ll x=1;
            for(ll i=n;i>=1;i--)
            {
                x=(x*i)%MOD;
                a[i]=x;
                if(a[i]<=0)
                {
                    //debug(i);
                }
            }
             x=1;
            for(ll i=2;i<=n;i++)
            {
                x=(x*i)%MOD;
                b[i]=(x-1+MOD)%MOD;
                if(b[i]<0)
                {
                    //debug(i);
                }
            }
            ll ans=1;
            if(n==1)
            {
                cout<<"1";

            }
            else if(n==2)
            {
                cout<<"2";
            }
            else
            {
                ans=a[1];
                for(ll i=2;i<n;i++)
                {
                    ans=(ans+(b[i]*a[i+1])%MOD)%MOD;
                }
                cout<<ans;
            }

            return 0;
}