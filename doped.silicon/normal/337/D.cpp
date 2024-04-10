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
#define INF (ll)1000000000000000000
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
ll dp[100007];
ll dp1[100007];
ll h[100007];
vector<ll>v[100007];
ll mark[100007];
ll dfs1(ll n)
{
    mark[n]=1;
    if(n!=1&&v[n].size()==1)
    {
        if(h[n]==1)
            dp[n]=0;
        else
            dp[n]=-INF;
        return dp[n];
    }
    else
    {
        ll x=-INF;
        rep(i,v[n].size())
        {
            if(mark[v[n][i]]==0)
            {
                x=max(dfs1(v[n][i]),x);
            }
        }
        dp[n]=x+1;
        if(h[n]==1)
        {
            dp[n]=max((ll)0,dp[n]);
        }
        return dp[n];
    }
}
void dfs2(ll n,ll m1,ll m2,ll up)
{
    // debug(n);
    mark[n]=1;
    if(dp[n]!=m1)
    {
        dp1[n]=max(up+1,m1+2);
    }
    else
    {
        dp1[n]=max(up+1,m2+2);
    }
    if(h[n]==1)
        dp1[n]=max(0ll,dp1[n]);

    // debug(dp1[n]);
    // debug(up);
    // debug(m1);
    // debug(m2);
    m1=-INF;
    m2=m1;
    rep(i,v[n].size())
    {
        // debug(v[n][i]);
        if(mark[v[n][i]]==0)
        {
            ll z=dp[v[n][i]];
            if(z>m1)
            {
                m2=m1;
                m1=z;
            }
            else if(z>m2)
            {
                m2=z;
            }
        }
    }
    rep(i,v[n].size())
    {
        if(mark[v[n][i]]==0)
        {
            dfs2(v[n][i],m1,m2,dp1[n]);
        }
    }
}
int main () 
{

    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n,m,d;
        cin>>n>>m>>d;
        rep(i,100007)
        {
            dp[i]=d;
        }
        rep(i,m)
        {
            ll x;
            cin>>x;
            h[x]=1;
        }
        rep(i,n-1)
        {
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs1(1);
        rep(i,100007)
            mark[i]=0;
        dfs2(1,-INF,-INF,-INF);
        ll ans=0;
        rep(i,n)
        {
            //dbug(dp[i+1],dp1[i+1]);
            if(max(dp[i+1],dp1[i+1])<=d)
                ans++;
        }
        cout<<ans<<endl;
            return 0;
}