#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ll long long
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
// #define MAXN 100000
#define MOD 1000000007
#define dec decr
bool prime[10000007];
void sieve() 
{
    ll n=10000007;
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 

//END OF COMPETITVE PROGRAMMING TEMPLATE
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
        ll n;
        cin>>n;
        ll ar[n];
        // cin>>n;
        rep(i,n)
        {
            cin>>ar[i];
        }
        ll t1=-1;
        ll c=INF;
        for(ll t=1;t<=110;t++)
        {
            ll cost=0;
            rep(i,n)
            {
                if(ar[i]>t)
                {
                    cost+=ar[i]-t-1;
                }
                else if(ar[i]<t)
                {
                    cost+=t-ar[i]-1;
                }
            }
            if(cost<c)
            {
                c=cost;
                t1=t;
            }
        }
        cout<<t1<<" "<<c;




            return 0;

}