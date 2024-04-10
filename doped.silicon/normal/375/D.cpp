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
#define INF 1000000000000000000
ll blk=317;
ll start[100005];
vector<ll>v[100005];
ll c[100005];
ll o[100005];
ll mark[100005];
ll k=1;
ll en[100005];
ll ans[100005];
ll freq[100005];
    ll clr[100005];

ll dfs(ll n)
{
    mark[n]=1;
    o[k]=c[n];
    start[n]=k;
    k++;
    rep(i,v[n].size())
    {
        if(!mark[v[n][i]])
        {
            dfs(v[n][i]);
        }
    }
    en[n]=k-1;
}
bool alg(pair<pair<ll,ll>,pair<ll,ll> > a,pair<pair<ll,ll>,pair<ll,ll> > b)
{
    if(a.ff.ff/blk!=b.ff.ff/blk)
    {
        return a.ff.ff<b.ff.ff;
    }
    else
        return a.ff.ss<b.ff.ss;
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
    ll n,q;
    cin>>n>>q;
    rep(i,n)
    {
        cin>>c[i+1];
    }
    rep(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    vector<pair<pair<ll,ll>,pair<ll,ll> > >v;
    rep(i,q)
    {
        ll a,b;
        cin>>a>>b;
        v.pb(mp(mp(start[a],en[a]),mp(b,i)));
    }
    sort(v.begin(),v.end(),alg);
    ll l=0,r=0;
    rep(i,q)
    {
        ll l1=v[i].ff.ff;
        ll r1=v[i].ff.ss;
        // debug(l1);
        // debug(r1);
        while(r<r1)
        {
            ll z=clr[o[r+1]]++;
            freq[z+1]++;
            r++;
        }
        while(l<l1)
        {
            ll z=clr[o[l]]--;
            freq[z]--;
            l++;
        }
        while(l>l1)
        {
            ll z=clr[o[l-1]]++;
            freq[z+1]++;
            l--;
        }
        while(r>r1)
        {
            ll z=clr[o[r]]--;
            freq[z]--;
            r--;
        }
        // debug(v[i].ss.ff);
        // rep(i1i,3)
        // {
        //     debug(clr[i1i+1]);
        // }
        ans[v[i].ss.ss]=freq[v[i].ss.ff];
    }
    rep(i,q)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}