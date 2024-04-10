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

int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll n,w;
            cin>>n>>w;
            ll z=0;
            ll a[n];
            ll b[n];
            ll ar[2*n];
            rep(i,n)
            {
                cin>>a[i];
                if(a[i]==1)
                {
                    z=1;   
                }
            }
            rep(i,n)
            {
                cin>>b[i];
                if(b[i]==1)
                    z=1;
            }
            ar[0]=b[0];
            ll a1=n-1,a2=n-1;
            for(ll i=1;i<2*n;i++)
            {
                if(i%2==1)
                {
                    ar[i]=a[a1];
                    a1--;
                }
                else
                {
                    ar[i]=b[a2];
                    a2--;
                }
            }
            if(z==1)
            {
                cout<<"-1";
            }
            else
            {
                double m=w;
                double ans=0;
                rep(i,2*n)
                {
                    m=w+ans;
                    // debug(i);
                    // debug(m);
                    // debug(ar[i]);
                    ans+=m/(ar[i]-1);
                    
                }
                //ans =6.45924582952834;
                cout<<setprecision(13)<<ans<<endl;
            }
            return 0;
}