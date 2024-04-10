#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ll long long

#define ld double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define INF 1000000000000000
#define MOD 1000000007
ll ans=0;
ll num=0;
bool alg(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.ss!=b.ss)
        return a.ss<b.ss;
    return a.ff<b.ff;
}
ll fin(vector<pair<ll,ll>> &v)
{
    sort(v.begin(),v.end(),alg);
    ll last=0,val=0;
    for(auto x:v)
    {
        if(x.ff>last)
        {
            val++;
            last=x.ss;
        }
    }
    return val;
}
void display(vector<pair<ll,ll>> &v)
{
    sort(v.begin(),v.end(),alg);
    ll last=0,val=0;
    for(auto x:v)
    {
        if(x.ff>last)
        {
            val++;
            cout<<x.ff<<" "<<x.ss<<endl;
            last=x.ss;
        }
    }
}
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
        ll ar[n];
        rep(i,n)
        {
            cin>>ar[i];
        }
        map<int,vector<pair<ll,ll>>>m;
        rep(i,n)
        {
            ll s=0;
            for(ll j=i;j<n;j++)
            {
                s+=ar[j];
                m[s].pb({i+1,j+1});
            }
        }
        for(auto &x:m)
        {
            ll z=fin(x.ss);
            if(z>ans)
            {
                ans=z;
                num=x.ff;
            }
        }
        cout<<ans<<endl;
        display(m[num]);

            return 0;

}