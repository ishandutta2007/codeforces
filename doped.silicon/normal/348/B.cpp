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

ll sum=0;
ll lcm(ll a,ll b)
{
    if(a==0&&b==0)
        return 1;
    if(a==0)
        return b;
    else if(b==0)
        return a;
    ll j= (a*b/gcd(a,b));
    if(a/gcd(a,b)>INF/b)
        return INF;
    else
        return j;

}
ll a[100007];
ll mark[100007];
vector<ll>g[100007];
ll ans=0;
pair<ll,ll> dfs(ll n)
{
    mark[n]=1;
    if(n!=1&&g[n].size()==1)
    {
        return mp(a[n-1],(ll)1);
    }
    ll mn=1e18, lm=1;
    ll mn2=mn;
    vector<ll>v;
    ll leaf=0,node=0;
    ll x=-1,xx=1;
    rep(i,g[n].size())
    {
        if(mark[g[n][i]]==0)
        {
            pair<ll,ll> p=dfs(g[n][i]);
            if(x==0)
            {
                x=p.ff;
            }
            {
            v.pb(p.ff);
            lm=lcm(lm,p.ss);
            mn=min(mn,p.ff);
            node++;
            }
            if(x!=p.ff)
                xx=0;
        }
     }
    ll z=(mn/lm)*lm;
    if(xx)
        z=mn;
    rep(i,v.size())
    {
        ans+=v[i]-z;
    }
    return mp(z*v.size(),node*lm);
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
            cin>>n;ll cage=0;
            rep(i,n)
            {
                cin>>a[i];
                sum+=a[i];
            }
            rep(i,n-1)
            {
                ll x,y;
                cin>>x>>y;
                g[x].pb(y);
                g[y].pb(x);
            }
            dfs(1);
            cout<<ans<<endl;
            return 0;
}