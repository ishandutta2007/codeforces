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
typedef pair<ll,ll> pll; 
vector<pair<ll,ll>>v[100010];
vector<ll>t[100101];
ll ans[100101];
 ll mark[100010];

int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            string s;
            cin>>s;
            ll ans=0;
            ll m=0,f=0,lf=0,mc=0;
            ll n=s.length();
            ll e=n-1;
            for(;e>=0;e--)
            {
                if(s[e]=='F')
                    break;
            }
            for(;e>=0;e--)
            {
                if(s[e]=='M')
                    break;
                lf++;
            }
             // debug(e);
            // debug(lf);
            if(e==-1)
            {
                cout<<"0"<<endl;
                return 0;
            }
            ll i=0;
            while(i<e&&s[i]=='F')
            {
                i++;
            }
            //debug(i);
            for(;i<=e;i++)
            {
                if(s[i]=='M')
                {
                    m=min((ll)0,m+1);
                    mc++;
                }
                if(s[i]=='F')
                {
                    m--;
                }
            }
            // debug(mc);
            // debug(abs(m));
            // debug(lf);
            cout<<mc+abs(m)+lf-1<<endl;
            return 0;
}