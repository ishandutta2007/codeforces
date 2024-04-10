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
ll n,m;
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
vector<pair<ll,pair<ll,ll> > >v;
ll ans[300007];
ll an[300007];
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
            
            cin>>n>>m;
            rep(i,m)
            {
                ll a,b,c;
                cin>>a>>b>>c;
                v.pb(mp(c,mp(a,b)));
            }
            ll fi=0;
            sort(v.begin(),v.end());
            rep(i,m)
            {
                // debug(v[i].ff);
                
                ll j = i;
                while(j < (m-1) && (v[(j+1)].ff == v[i].ff))
                    j++;
                for(ll k=i;k<=j;k++)
                {
                    ll c=v[k].ff;
                    ll b=v[k].ss.ss;
                    ll a=v[k].ss.ff;
                    if(ans[b]<an[a]+1)
                    {
                        ans[b]=an[a]+1;
                        fi=max(fi,an[a]+1);
                    }
                }
                for(ll k=i;k<=j;k++)
                {
                    ll b=v[k].ss.ss;
                    an[b]=ans[b];
                }
                i=j;
            }
            cout<<fi;

            
        return 0;
}