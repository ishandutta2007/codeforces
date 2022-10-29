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
 
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll a,b;
        string s1,s2;
        cin>>a>>b>>s1>>s2;
        ll l1=s1.length();
        ll l2=s2.length();
        ll ar[l2]={0};
        rep(i,l2)
        {
            ll x=i;
            rep(j,l1)
            {
                // debug(s1[x]);
                // debug(s2[j]);
                if(s2[x]==s1[j])
                {
                    x++;
                    ar[i]++;
                    if(x==l2)
                        x=0;
                }
            }
            // debug(ar[i]);
        }
        ll ans=0;
        ll x=0;
        rep(i,a)
        {
            ans+=ar[x];
            x=(x+ar[x])%l2;
        }
        cout<<(ans/l2)/b;
        return 0;
}