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
            ll ans=0;
            vector<pair<ll,ll>>v1;
            rep(i,n-1)
            {
                ll a,b;
                cin>>a>>b;
                v1.pb(mp(a,b));
                v[a].pb(b);
                v[b].pb(a); 
            }
            for(ll i=1;i<=n;i++)
            {
            for(ll j1=1;j1<=n;j1++)
            {
                if(j1==i)
                {
                    j1++;
                    continue;
                }
                rep(j,202)
                {
                    mark[j]=0;
                }
                ll a=i;
                ll b=j1;
                mark[a]=1;
                mark[b]=1;
                ll m1=0,m2=0;
                ll a1;
                rep(i1,v[a].size())
                {
                    if(mark[v[a][i1]]==0)
                    {
                        ll z=dia(v[a][i1]);
                        if(z>m1)
                        {
                            m2=m1;
                            m1=z;
                        }
                        else if(m2<z)
                        {
                            m2=z;
                        }
                    }
                }
                a1=m1+m2;
                m1=0;
                m2=0;
                rep(i1,v[b].size())
                {
                    if(mark[v[b][i1]]==0)
                    {
                        ll z=dia(v[b][i1]);
                        if(z>m1)
                        {
                            m2=m1;
                            m1=z;
                        }
                        else if(m2<z)
                        {
                            m2=z;
                        }
                    }
                }
                // debug(a1);
                // debug(m1+m2);
                ans=max(ans,(m1+m2)*a1);
            }
            }
            cout<<ans<<endl;
            return 0;
}