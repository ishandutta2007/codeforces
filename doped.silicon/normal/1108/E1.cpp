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
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
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
            ll ar[n+1]={0};
            vector<pair<ll,ll> >v;
            rep(i,n)
            {
                cin>>ar[i+1];
            }
            rep(i,m)
            {
                ll a,b;
                cin>>a>>b;
                v.pb(mp(a,b));
            }
            pair<ll,ll>ans;
            ll ans1=0;
            ll step=0;
            for(ll i=1;i<=n;i++)
            {
                for(ll j=i+1;j<=n;j++)
                {
                    ll x=ar[i];
                    ll y=ar[j];
                    ll a=0,b=0;
                    rep(k,m)
                    {
                        ll x1=v[k].ff;
                        ll y1=v[k].ss;
                        if(i>=x1&&i<=y1&&!(j>=x1&&j<=y1))
                        {
                            a++;
                        }
                        else if(!(i>=x1&&i<=y1)&&(j>=x1&&j<=y1))
                        {
                            b++;
                        }
                    }
                    // debug(max(abs(x-a-y),abs(y-b-x)));
                    // if(max(abs(x-a-y),abs(y-b-x))==6)
                    // {
                    //     debug(i);
                    //     debug(j);
                    //     debug(a);
                    //     debug(b);
                    // }
                    if(ans1<max(abs(x-a-y),abs(y-b-x)))
                    {
                        ans1=max(abs(x-a-y),abs(y-b-x));

                        if(abs(x-a-y)>abs(y-b-x))
                        {
                            ans=mp(j,i);
                        }
                        else
                        {
                            ans=mp(i,j);
                        }
                    }
                }
            }
            cout<<ans1<<endl;
            vector<ll>pt;
            ll a=0;
            ll j=ans.ff;
            ll i=ans.ss;
            rep(k,m)
            {
                ll x1=v[k].ff;
                ll y1=v[k].ss;
                if(i>=x1&&i<=y1&&!(j>=x1&&j<=y1))
                {
                    a++;
                    pt.pb(k+1);
                }
            }
            cout<<a<<endl;
            rep(i,pt.size())
            {
                cout<<pt[i]<<" ";
            }
            
        return 0;
}