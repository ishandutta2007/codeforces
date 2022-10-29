#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld long double
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
#define MOD 998244353
#define dec decr
#define endl '\n'
auto clk=clock();
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
ll sub[300007];
signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(15);
        cout<<fixed;
        mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll>>v;
        vector<pair<ll,ll>>da;

        rep(i,n)
        {
            ll a,b;
            cin>>a>>b;
            da.pb(mp(a,b));
            v.pb(mp(a-b,i));
            // v.pb(a-b);
        }
        sort(all(v));
        ll s1[n+1]={0};
        ll s2[n+1]={0};
        ll pos[n]={0};
        rep(i,n)
        {
            ll z=v[i].ss;
            pos[v[i].ss]=i;
            s1[i+1]+=s1[i]+da[z].ff;
            s2[i+1]+=s2[i]+da[z ].ss;
        }
        rep(i,m)
        {
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            ll z=min(da[a].ff+da[b].ss,da[a].ss+da[b].ff);
            sub[a]-=z;
            sub[b]-=z;
        }
        rep(i,n)
        {
            ll z=v[i].ss;        }
        rep(i,n)
        {
            ll x=pos[i];
            ll z=s1[x]+s2[n]-s2[x+1];
            // debug(s1[x]);
            // debug(s2[n]-s2[x+1]);
            z+=sub[i];
            z+=x*da[i].ss+(n-x-1)*da[i].ff;
            cout<<z<<" ";
        }








}