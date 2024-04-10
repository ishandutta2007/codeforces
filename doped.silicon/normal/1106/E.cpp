#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl
 
#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<pair<pair<ll,ll> ,pair<ll,ll> > >v;
ll now[100007];
ll n;
ll dp[100005][205];
#define INF 1000000000000000000
ll fun(ll l ,ll x)
{
    if(l==n)
    {
        return dp[l][x]=0;
    }
    else if(dp[l][x]!=-1)
    {
        return dp[l][x];
    }
    if(now[l]==-1)
    {
        return dp[l][x]=fun(l+1,x);
    }
    ll mn=v[now[l]].ss.ss+fun(v[now[l]].ss.ff,x);
    if(x>=1)
    {
        mn=min(mn,fun(l+1,x-1));
    }
    return dp[l][x]=mn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long double pi= 3.14159265358979323846;
    ll m,k;
    cin>>n>>m>>k;
    rep(i,100005)
    {
        rep(j,205)
        {
            dp[i][j]=-1;
        }
    }
    rep(i,k)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        v.pb(mp(mp(a,b),mp(c,d)));
    }
    sort(v.begin(),v.end());
    set<pair<pair<ll,ll>,pair<ll,ll> > > s2;
    ll k2=0;
    rep(i,n)
    {
        while(k2<k&&v[k2].ff.ff==i)
        {
            s2.insert(mp(mp(v[k2].ss.ss,v[k2].ss.ff),mp(k2,v[k2].ff.ss)));
            k2++;
        }
        while(!s2.empty()&&(*s2.rbegin()).ss.ss<i)
        {
            s2.erase(s2.find(*(s2.rbegin())));
        }
        if(s2.empty())
        {
            now[i]=-1;
        }
        else
            now[i]=(*s2.rbegin()).ss.ff;
    }
    cout<<fun(0,m);
    return 0;
}