#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define ll long long

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000000000000
#define PI 3.14159265358979323846L
bool alg(pair<ll, pair<ll, ll> > a,pair<ll, pair<ll, ll> > b)
{
    if(a.ff!=b.ff)
    {
        return a.ff<b.ff;
    }
    if(a.ss.ff!=b.ss.ff)
    {
        return a.ss.ff<b.ss.ff;   
    }
    return a.ss.ss>b.ss.ss;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll>v[100005];
ll mark[100005];
ld ans=0;
void find(ll x,ld d)
{
    mark[x]=1;
    ans+=1.0/d;
    for(auto z:v[x])
    {
        if(mark[z]==0)
        {
            find(z,d+1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(9);
    cout<<fixed;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    rep(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    find(1,1);
    cout<<ans;



    return 0;
}