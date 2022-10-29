#pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
 
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<'\n'
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
#define y0 yyyyyy0
auto clk=clock();
#define setb __builtin_popcount
#define PI 3.1415926535897932385
#define INF 100000000000000000ll
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define dec decr
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll st[800030];
void update(ll v,ll tl,ll tr,ll pos,ll x)
{
    if(tl==tr)
    {
        st[v]=x;
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(tm>=pos)
        {
            update(2*v,tl,tm,pos,x);
        }
        else
        {
            update(2*v+1,tm+1,tr,pos,x);
        }
        st[v]=st[2*v]+st[2*v+1];
    }
}
ll get(ll v,ll tl,ll tr,ll x)
{
    if(x<0)
        return -1;
    if(tl==tr)
    {
        ll ans=0;
        if(st[v]<=x)
        {
            ans = tl;
        }
        else
        {
            ans=  -1;
        }
        return ans;
    }
    else
    {
        ll tm=(tl+tr)/2;
        ll xx=tm;
        if(st[2*v]>x)
        {
            xx=get(2*v,tl,tm,x);
        }
        if(xx==tm)
        {
            xx=max(xx,get(2*v+1,tm+1,tr,x-st[2*v]));
        }
        return xx;
    }
}
void solve()
{
    ll n;
    cin>>n;
    ll ar[n]={0};
    ll ans[n]={0};
    rep(i,n)
    {
        cin>>ar[i];
        update(1,0,n-1,i,i);
    }
    for(ll i=n-1;i>=0;i--)
    {
        ans[i]=get(1,0,n-1,ar[i]);
        ans[i]++;
        if(ans[i]!=n)
        update(1,0,n-1,ans[i],0);
    }
    rep(i,n)
    {
        cout<<ans[i]<<' ';
    }
}
signed main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}