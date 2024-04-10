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
#define INF 1000000000000000000ll
#define EPS 1e-7
// #define MAXN 100000
#define MOD 1000000007
#define dec decr
// ll ans[10000000];
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
        ll t;
        cin>>t;
        // debug(t);
        ll ar[32]={0};
        ll ar2[61]={0};
        ll z=1;
        ll zz=1;
        rep(i,32)
        {
            ar[i]=z;
            z*=4;
        }
        rep(i,61)
        {
            ar2[i]=(zz-1);
            zz*=2;
        }
        while(t--)
        {
            ll n,k;
            cin>>n>>k;
            if(n<=31)
            {
                z=(ar[n]-1)/3;
            }
            if(n>=32)
            {
                cout<<"YES "<<n-1<<endl;
            }
            else if(n<=31&&z<k)
            {
                cout<<"NO"<<endl;
            }
            else 
            {
                ll p=0;
                ll k1=0;
                ll j=0;
                for(ll i=1;i<=min(31ll,n);i++)
                {
                    if(k<p+ar2[i])
                    {
                        break;
                    }
                    else
                    {
                        p+=ar2[i];
                        k1++;
                        z=(ar[k1]-1)/3;
                        zz=(ar[n-k1]-1)/3;
                        j+=z*zz;
                        // debug(p);
                        // debug(j);
                    }
                    
                }
                // debug(p);
                // debug(j);
                k-=p;
                if(j>=k||n>2)
                cout<<"YES "<<n-k1<<endl;
                else
                {
                    cout<<"NO"<<endl;
                }
            }
        }

            return 0;
}