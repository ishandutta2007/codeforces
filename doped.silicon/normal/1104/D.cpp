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
        string s;
        cin>>s;
        char x;
        while(s!="end")
        {
            cout<<"? 0 1"<<endl<<flush;

            cin>>x;
            if(x=='x')
            {
                cout<<"! 1"<<endl<<flush;
            }
            else
            {
                ll ans=-1;
                ll a=0,b=1;
                while(x!='x')
                {
                    a=b;
                    b=2*a;
                    cout<<"? "<<a<<" "<<b<<endl<<flush;
                    cin>>x;
                }
                while(a<=b)
                {
                    if(b==(a+1))
                    {
                        cout<<"! "<<b<<endl<<flush;
                        break;
                    }
                    ll mid=(a+b)/2;
                    cout<<"? "<<a<<" "<<mid<<endl<<flush;
                    cin>>x;
                    if('x'==x)
                    {
                        b=mid;
                    }
                    else
                    {
                        a=mid;
                    }
                }
            }
            cin>>s;
        }

            return 0;

}