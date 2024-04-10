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
int main () 
{

    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll t;
        cin>>t;
        while(t--)
        {
            ll n;
            cin>>n;
            ll ans[n]={0};
            vector<pair<ll,pair<ll,ll> > >v;
            rep(i,n)
            {
                ll a,b;
                cin>>a>>b;
                v.pb(mp(a,mp(b,i)));
            }
            sort(v.begin(),v.end());
            ll cur=1;
            ll prev=v[0].ff;
            rep(i,n)
            {
                if(cur==2)
                {
                    ans[v[i].ss.ss]=2;
                }
                else
                {
                    ll a=v[i].ff;
                    ll b=v[i].ss.ff;
                    ll c=v[i].ss.ss;
                    if(a>prev)
                    {
                        ans[v[i].ss.ss]=2;
                        cur=2;
                    }
                    else
                    {
                        ans[v[i].ss.ss]=1;
                        prev=max(prev,b);
                    }
                }
            }
            if(cur==1)
            {
                cout<<"-1"<<endl;
            }
            else{
                rep(i,n)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<""<<endl;
            }
        }
        return 0;
}