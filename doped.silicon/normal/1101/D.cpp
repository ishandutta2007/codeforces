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
vector<ll>g[200009];
ll a[200009];
set<ll> v[200009];

ll ans=1;
ll z=0;
ll dfs(ll n,ll k)
{
    v[k].erase(n);
    vector<ll> now;
    ll p=0;
    rep(i,g[n].size())
    {
        if(v[k].find(g[n][i])!=v[k].end())
        {
            now.pb(g[n][i]);
            p++;
        }
    }
    if(p==0)
        return 1;
    ll m1=0,m2=0;
    rep(i,p)
    {
        ll x=dfs(now[i],k);
        if(x>m1)
        {
            m2=m1;
            m1=x;
        }
        else if(x>m2)
        {
            m2=x;
        }
    }
    ans=max(m1+m2+1,ans);
    return m1+1;
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
                cin>>a[i];
                ll x=a[i];
                for(ll j=2;j*j<=x;j++)
                {
                    if(x%j==0)
                    {
                        v[j].insert(i+1);
                        while(x%j==0)
                        {
                            x/=j;
                        }
                    }
                }
                if(x>=2)
                {
                    v[x].insert(i+1);
                }
        }
        rep(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        rep(i,200009)
        {
            if(v[i].size()>1)
            {
            // debug(v[i].size());
            // debug(i);
                z=1;
               // debug(*v[i].begin());
                while(v[i].size()>=1)
                {
                dfs(*v[i].begin(),i);
                }
            }
        }
        if(z)
        {
            cout<<ans;
        }
        else
        {
            cout<<"0";
        }
        return 0;
}