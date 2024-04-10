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
ll s[100008]={0};
        vector<ll>v[100007];
ll mark[100008];
ll ans=0;
void dfs(ll n,ll sum)
{
    mark[n]=1;
    ll z;
    if(s[n]==-1)
    {
        z=0;
        ll x=INF;
        for(auto i:v[n])
        {
            if(mark[i]==0&&s[i]!=-1)
            {
                x=min(x,s[i]);
            }
        }
        if(x!=INF&&z+sum>x)
        {
            cout<<"-1";
            exit(0);
        }
        ll p=0;
        if(x==INF)
        {
            ans+=z;
            p=z;
        }
        else
        {
            ans+=x-sum;
            p=x-sum;
        }
        for(auto i:v[n])
        {
            if(mark[i]==0)
            {
                dfs(i,p+sum);
            }
        }
    }
    else
    {
        z=s[n]-sum;
        if(z<0)
        {
            cout<<"-1";
            exit(0);
        }
        ans+=z;
        for(auto i:v[n])
        {
            if(mark[i]==0)
            {
                dfs(i,s[n]);
            }
        }
    }
    
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
        rep(i,n-1)
        {
            ll x;
            cin>>x;
            v[x].pb(i+2);
        }
        rep(i,n)
        {
            cin>>s[i+1];
        }
        dfs(1,0);
        cout<<ans;




            return 0;
}