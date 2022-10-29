#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;
#define ll long long

typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
ordered_set s;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second





#define PI 3.1415926535897932385
#define INF 1000000000000000
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
        cout<<setprecision(2);
        cout<<fixed;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n,t;
        cin>>n>>t;
        ll ar[n];
        ordered_set s;
        ll sum=0,su=0;
        ll ans=0;
        rep(i,n)
        {
            cin>>ar[i];
            su+=ar[i];
            // ll req=t-ar[i]+1;
            // ll x=s.order_of_key(mp(req,0));
            // ans+=x;
            // sum+=ar[i];
            // s.insert(mp(sum,i));
            // debug(ans);
        }
        for(ll i=n-1;i>=0;i--)
        {
            sum+=ar[i];
            s.insert(mp(sum,i));
        }
        ll z=0;
        for(ll i=n-1;i>=0;i--)
        {
            ll req=t+z;
            z+=ar[i];
         // /   debug(z);
            // debug(req);
            ll x=s.order_of_key(mp(req,0));
            ans+=x;
            s.erase(s.find(mp(z,i)));
            // debug(ans);
        }
        cout<<ans;





            return 0;

}