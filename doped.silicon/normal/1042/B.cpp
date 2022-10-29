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
        ll n;
        cin>>n;
        ll dp[1<<3];
        rep(i,1<<3)
        {
            dp[i]=INF;
        }
        ll ma=0;
        rep(i,n)
        {
            ll c;
            cin>>c;
            string s;
            cin>>s;
            ll mask=0;
            rep(j,s.length())
            {
                if(s[j]=='A')
                {
                    mask+=4;
                }
                else if(s[j]=='B')
                {
                    mask+=2;
                }
                else
                {
                    mask+=1;
                }
            }
            // debug(mask);
            ma|=mask;
            // debug(ma);
            dp[mask]=min(dp[mask],c);
        }
        if(ma!=7)
        {
            cout<<"-1";
        }
        else
        {
            rep(i,8)
            {
                rep(j,8)
                {
                    dp[i|j]=min(dp[i|j],dp[i]+dp[j]);
                }

            }
            cout<<dp[ma];

        }





            return 0;

}