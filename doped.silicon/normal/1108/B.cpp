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
            ll n;
            cin>>n;
            set<ll> s1,s2;
            ll ma=0;
            rep(i,n)
            {
                ll x;
                cin>>x;
                if(s1.find(x)==s1.end())
                {
                    s1.insert(x);
                }
                else
                {
                    s2.insert(x);
                }
                ma=max(ma,x);
            }            
            ll x=1,y=1;
            for (set<ll>::iterator it=s1.begin(); it!=s1.end(); ++it)
            {
                // debug(*it);
                x=lcm(x,*it);
            }
            for (set<ll>::iterator it=s2.begin(); it!=s2.end(); ++it)
            {
                y=lcm(y,*it);
            } 
            ll z=x/ma;
            x=ma;
            y=z*y;
            cout<<x<<" "<<y;
        return 0;
}