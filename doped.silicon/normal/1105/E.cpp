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
ll ar[50];
ll cur=0;
ll dp[1<<20];
ll solve(ll mask)
{
    if(mask<(1ll<<20)&&dp[mask]!=-1)
    {
        return dp[mask];
    }
    // debug(mask);
    if(mask==0)
        return 0;
    ll ans=0;
    ll x=log2(mask);
    ans=max(ans,solve(mask^(1ll<<x)));
    ans=max(ans,solve((mask^(1ll<<x))&ar[x])+1);
    if(mask<(1ll<<20))
        return dp[mask]=ans;
    return ans;
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
        rep(i,(1ll<<20))
        {
            dp[i]=-1;
        }
        ll n,m;
        cin>>n>>m;
        map<string,ll>mp;
        ll v[50]={0};
        rep(i,n+1)
        {
            ll x=1;
            if(i!=n)cin>>x;
            if(x==2)
            {
                string s;
                cin>>s;
                if(mp.count(s)==0)mp[s]=cur++;
                ll z=mp[s];
                v[z]=1;
            }
            else
            {
                rep(j,40)
                {
                    for(ll k=j+1;k<40;k++)
                    {
                        if(v[j]&&v[k])
                        {
                            // debug(j);
                            // debug(k);
                            // debug(i);
                            ar[j]|=1ll<<k;
                            ar[k]|=1ll<<j;
                        }
                    }
                }
                rep(j,40)
                {
                    v[j]=0;
                }
            }

        }
        rep(i,m)
        {
            // debug(ar[i]);
        }
        rep(i,40)
        {
            ar[i]=ar[i]^((1ll<<m)-1);
        }
        rep(i,m)
        {
            // debug(ar[i]);
        }
        // debug((1<<m)-1);
        cout<<solve((1ll<<m)-1)<<endl;

            return 0;

}