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
ll w[300020];
vector<pair<ll,ll>>v[300020];
ll mark[300020];
ll ans[300020];
ll dfs(ll n)
{
    //dbug(n,n);
    mark[n]=1;
    ll pet=w[n];
    ll m1=0,m2=0;
    rep(i,v[n].size())
    {

        ll n1=v[n][i].first;
        ll l=v[n][i].second;
        ll k=0;
        if(mark[n1]==0)
        {
            //debug(n1);
            k=dfs(n1);
            
        }
        if(k-l>m1)
        {
            m2=m1;
            m1=k-l;
        }
        else if(k-l>m2)
            {m2=k-l;}

    }
    ans[n]=pet+m1+m2;
    // debug(m2);
    // debug(pet+m1+m2);
    // debug(m1);
    return pet+m1;
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
            rep(i,n)
            {
                cin>>w[i+1];
            }
            rep(i,n-1)
            {
                ll a,b,c;
                cin>>a>>b>>c;
                v[a].pb(mp(b,c));
                v[b].pb(mp(a,c));
            }
            ll z= dfs(1);
            ll xx=0;
            rep(i,n)
            {
                xx=max(ans[i+1],xx);
            }
            cout<<xx<<endl;
            return 0;
}