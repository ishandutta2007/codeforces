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
vector<ll>v[300007];
ll s=0;
ll s1=0;
ll p=0;
ll x,y;
ll mark[300007];

ll mark1[300007];
ll mar[300007];
ll dfs(ll z)
{
    // debug(z);
    mark[z]=1;
    ll ma=0;
    rep(i,v[z].size())
    {
        if(v[z][i]==y)
        {
            mark[v[z][i]]==1;
            // debug("afsd");
            // debug(z);
            s=z;
            return 1;
        }
        else if(mark[v[z][i]]==0)
        {
            // debug(v[z][i]);
            ma=max(dfs(v[z][i]),ma);
        }
    }
    if(ma==0)
        return 0;
    else return ma+1;
}
ll dfs11(ll z)
{
    // debug(z);
    mark1[z]=1;
    ll ma=0;
    rep(i,v[z].size())
    {
        if(v[z][i]==x)
        {
            mark1[v[z][i]]==1;
            // debug("afsd");
            // debug(z);
            s1=z;
            return 1;
        }
        else if(mark1[v[z][i]]==0)
        {
            // debug(v[z][i]);
            ma=max(dfs11(v[z][i]),ma);
        }
    }
    if(ma==0)
        return 0;
    else return ma+1;
}
ll dfs1(ll z)
{
    mar[z]=1;
    ll ma=0;
    // debug(ma);
    rep(i,v[z].size())
    {
        if(mar[v[z][i]]!=1&&v[z][i]!=s)
        {
            ll xx=dfs1(v[z][i]);
            // debug(xx);
            // debug(v[z][i]);
            ma+=xx;
            // debug(ma);
        }
        // debug(ma);
    }
    // debug(ma);
    return ma+1;
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
            cin>>x>>y;
            rep(i,n-1)
            {
                ll a,b;
                cin>>a>>b;
                v[a].pb(b);
                v[b].pb(a);
            }
            // debug(y);
            dfs(x);
            dfs11(y);
            ll k=dfs1(y);
            rep(i,300007)
            {
                mar[i]=0;
            }
            s=s1;
            // debug(s1);
            ll k1=dfs1(x);
            // dbug(k,k1);
            
            // debug(z);
            cout<<n*(n-1)-k*k1;
        return 0;
}