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
ll k=448;
ll a[200007]={0},ans[200007]={0},cnt[1000006]={0};
ll answ=0;
#define INF 100000000000000000
bool alg(pair<ll,pair<ll,ll> > a,pair<ll,pair<ll,ll> > b)
{
    if(b.ss.ff/k!=a.ss.ff/k)
    {
        return a.ss.ff<b.ss.ff;
    }
    return
    a.ss.ss<b.ss.ss;
}
void addt(ll l)
{
    answ+=(2*cnt[a[l]]+1)*a[l];
    cnt[a[l]]++;
}
void subt(ll l)
{
    cnt[a[l]]--;
    answ-=(2*cnt[a[l]]+1)*a[l];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double pi= 3.14159265358979323846;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,q;
    cin>>n>>q;

    rep(i,n)
    {
        cin>>a[i];
    }
    vector<pair<ll,pair<ll,ll> > >v;
    rep(i,q)
    {
        ll a1,b1;
        cin>>a1>>b1;
        a1--;
        b1--;
        v.pb(mp(i,mp(a1,b1)));
    }
    ll l=0,r=0;
    answ=a[0];
    cnt[a[0]]=1;
    sort(v.begin(),v.end(),alg);
    rep(i,q)
    {
        ll cr=v[i].ss.ss;
        ll cl=v[i].ss.ff;
        while(cr>r)
        {
            addt(++r);
        }
        while(cl>l)
        {
            subt(l++);
        }
        while(cl<l)
        {
            addt(--l);
        }
        while(cr<r)
        {
            subt(r--);
        }
        ans[v[i].ff]=answ;
    }
    rep(i,q)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}