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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long double pi= 3.14159265358979323846;
    ll n,m;
    cin>>n>>m;
    ll rem[n];
    ll cost[n];
    rep(i,n)
    {
        cin>>rem[i];
    }
    vector<pair<ll,ll> >v;
    rep(i,n)
    {
        ll a;
        cin>>a;
        cost[i]=a;
        v.pb(mp(a,i));
    }
    sort(v.begin(),v.end());
    ll a=0;
    ll z=1;
    rep(i,m)
    {
        if(!z)
        {
            cout<<"0"<<endl;
        }
        else
        {
        ll ans=0;
        ll t,d;
        cin>>t>>d;
        t--;
        if(rem[t]>=d)
        {
            ans+=d*cost[t];
            rem[t]-=d;
        }
        else
        {
            ans+=cost[t]*rem[t];
            d-=rem[t];
            rem[t]=0;
            // debug(ans);
            while(a!=n&&d>0)
            {
                ll a1=v[a].ss;
                if(rem[a1]>=d)
                {
                    ans+=d*cost[a1];
                    rem[a1]-=d;
                    d=0;
                }
                else
                {
                    ans+=cost[a1]*rem[a1];
                    d-=rem[a1];
                    rem[a1]=0;
                    a++;
                }
            }
        }
        if(a==n)
        {
            z=0;
        }
        if(z)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }}
    }
    return 0;
}