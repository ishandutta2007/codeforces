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
// ll ans[10000000];
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
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
        ll n,m;
        cin>>n>>m;
        if(m<n-1)
        {
            cout<<"Impossible";
            return 0;
        }
        
        set<pair<ll,ll>>v;
        rep(i,n-1)
        {
            v.insert({i+1,i+2});
        }
        ll flag=1;
        for(ll i=1;i<=n&&flag;i++)
        {
            vector<ll>s;
            for(ll j=i+1;j<=2*i&&j<=n;j++)
            {
                if(gcd(i,j)==1)
                    s.pb(j);
            }
            // debug(v.size());
            for(auto x:s)
            {
                ll z=x;
                // debug(x);
                while(z<=n)
                {
                    v.insert(mp(i,z));
                    z+=i;
                    // debug(v.size());
                    if(v.size()==m)
                    {
                        flag =0;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }
        }
        if(v.size()==m)
        {
            cout<<"Possible"<<endl;
            for(auto x:v)
            {
                cout<<x.ff<<" "<<x.ss<<endl;
            }

        }
        else
        {
            cout<<"Impossible";
        }


            return 0;
}