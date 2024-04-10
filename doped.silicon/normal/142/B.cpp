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
#define INF 1000000000000000000
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
vector<ll>v[202];
ll mark[202];
ll dia(ll n)
{
    mark[n]=1;
    ll x=0;
    rep(i,v[n].size())
    {
        if(mark[v[n][i]]==0)
        {
            x=max(x,dia(v[n][i]));
        }
    }
    return x+1;
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
            cin>>n>>m;
            if(n==1||m==1||(n==2&&m==2))
            {
                cout<<n*m;
                return 0;
            }
            if((n==2&&m%2==1)||(n%2==1&&m==2))
            {
                cout<<n*m/2+1<<endl;
                return 0;
            }
            else if((n==2&&m%4==2)||(n%4==2&&m==2))
            {
                cout<<n*m/2+2<<endl;
                return 0;
            }
            else
            {
                cout<<(n*m+1)/2;
            }
            
            return 0;
}