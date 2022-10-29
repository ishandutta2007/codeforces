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
        ll dp[100007][3]={0};

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
        ll n,l,r;
        cin>>n>>l>>r;
        ll a=0,b=0,c=0;
        ll z=(r-l+1);
        if(l%3==0)
        {
            a=(z+2)/3;
            b=(z+1)/3;
            c=(z)/3;
        }
        else if(l%3==1)
        {
            a=(z)/3;
            b=(z+2)/3;
            c=(z+1)/3;
        }
        else
        {
            a=(z+1)/3;
            b=(z)/3;
            c=(z+2)/3;
        }
        dp[1][1]=b;
        dp[1][2]=c;
        dp[1][0]=a;

        for(ll i=2;i<=n;i++)
        {
            dp[i][0]=(dp[i-1][0]*a+dp[i-1][1]*c+dp[i-1][2]*b)%MOD;
            dp[i][1]=(dp[i-1][0]*b+dp[i-1][1]*a+dp[i-1][2]*c)%MOD;
            dp[i][2]=(dp[i-1][0]*c+dp[i-1][1]*b+dp[i-1][2]*a)%MOD;
            // dp[i][2]=dp[i-1][0]+a+dp[i-1][1]+c+dp[i-1][2]+b;
            // dp[i][1]=dp[i-1][0]+a+dp[i-1][1]+c+dp[i-1][2]+b;

        }
        cout<<dp[n][0];



            return 0;

}