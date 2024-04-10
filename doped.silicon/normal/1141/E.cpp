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
        ll hp,n;
        cin>>hp>>n;
        ll ar[n];
        rep(i,n)
        {
            cin>>ar[i];
        }
        
        rep(i,n-1)
        {
            ar[i+1]+=ar[i];
        }
        ll ans=0;
        // debug(ans);
        ll m=INF;
        rep(i,n)
        {
            m=min(m,ar[i]);
            ans++;
            if(ar[i]+hp<=0)
            {
                cout<<ans;
                return 0;
            }
        }
        // debug(ans);
        // debug(ar[n-1]);
        ans=0;
        if(ar[n-1]>=0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        ll x=(hp+m+-ar[n-1]-1)/(-ar[n-1]);
        hp+=x*ar[n-1];
        // debug(x);
        // debug(ans);
        // debug(hp);
        ans=(x*n);
        if(hp==0)
        {
            cout<<ans;
            return 0;
        }
        rep(i,n)
        {  
             ans++;
            if(ar[i]+hp<=0)
            {
                cout<<ans<<endl;
                return 0;
            }
        }


            return 0;

}