#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ll long long
#define int long long

#define ld double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define INF 1000000000000000
#define MOD 1000000007

signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(11);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n;
        cin>>n;
        ll ar[n]={0};
        rep(i,n)
        {
            cin>>ar[i];
        }
        ll a=0,b=0;
        ll i=0;
        while(ar[i]==1)
        {
            a++;
            i++;
        }
        i=n-1;
        while(ar[i]==1)
        {
            b++;
            i--;
        }
        ll ans=a+b;
        a=0;
        rep(i,n)
        {
            if(ar[i]==1)
            {
                a++;
            }
            else
            {
                a=0;
            }
            ans=max(ans,a);
        }
        cout<<ans;
            return 0;

}