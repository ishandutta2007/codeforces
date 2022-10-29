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
        ll q[n-1]={0};
        rep(i,n-1)
        {
            cin>>q[i];
        }
        ar[n-1]=n+1;
        for(ll i=n-2;i>=0;i--)
        {
            ar[i]=ar[i+1]-q[i];
            // debug(ar[i]);
        }
        ll m=INF;
        rep(i,n)
        {
            m=min(m,ar[i]);
        } 
        m--;
        // // debug(m);
        ll check[n+1]={0};
        check[0]=1;
        rep(i,n)
        {
            ar[i]-=m;
        }
        rep(i,n)
        {
            if(ar[i]>n)
            {
                // debug(i);
                // debug(ar[i]);
                cout<<"-1";
                return 0;
            }
            check[ar[i]]=1;
        }
        rep(i,n+1)
        {
            if(check[i]!=1)
            {
                // debug(i);
                cout<<"-1";
                return 0;
            }
        }
        rep(i,n)
        {
            cout<<ar[i]<<" ";
        }


            return 0;

}