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
            ll n,m;
            cin>>m>>n;
            ll ar[n];
            rep(i,n)
            {
                cout<<m<<endl<<flush;
                ll x;
                cin>>x;
                if(x==0)
                {
                    cout<<m<<endl;
                    return 0;
                }
                else if(x==-1)
                {
                    ar[i]=1;
                }
                else
                {
                    ar[i]=-1;
                }
            }
            ll x=1;
            ll l=1,r=m;
            ll mid;
            ll p=0;
            while(l<=r)
            {
                mid=(l+r)/2;
                cout<<mid<<endl<<flush;
                cin>>x;
                if(x==0)
                {
                    cout<<mid<<endl;
                    return 0;
                }
                else if(x*ar[p]==-1)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                p=(p+1)%n;
            }
            return 0;
}