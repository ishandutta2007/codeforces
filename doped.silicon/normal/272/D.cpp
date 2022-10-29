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
            ll n;
            cin>>n;
            ll a[n];
            ll b[n];
            vector<ll>v,v2,v3;
            ll c=0;
            rep(i,n)
            {
                cin>>a[i];
                v.pb(a[i]);
            }
            rep(i,n)
            {
                cin>>b[i];
                v.pb(b[i]);
            }
            rep(i,n)
            {
                if(a[i]==b[i])
                    c++;
            }
            sort(v.begin(),v.end());
            rep(i,2*n)
            {
                ll x=1;
                //debug(i);
                while(i<2*n-1&&v[i]==v[i+1])
                {
                    i++;
                    x++;
                    //debug(i);
                }
                v2.pb(x);
                if(x>1)
                i--;
            }
            ll x=1;

            rep(i,v2.size())
            {
                ll z=v2[i];
                for(ll k=2;k<=z;k++)
                {
                    x*=k;
                    if(x>1000000000000)
                    {
                        while(x%2==0&&c)
                        {
                            x/=2;
                            c--;
                        }
                        v3.pb(x);
                        x=1;
                    }
                }
            }
            while(x%2==0&&c)
            {
                x/=2;
                c--;
            }
            v3.pb(x);
            ll ans=1;
            ll m;
            cin>>m;
            rep(i,v3.size())
            {
                ans=((ans%m)*(v3[i]%m))%m;
            }
            cout<<ans;
            return 0;
}