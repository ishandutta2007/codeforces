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
vector<ll> v[100005];
map<ll,ll>m;
ll ans=0;
void find(ll x,ll k)
{
    // debug(x);
    // debug(k);
    if(ans==100000)
    {
        exit(0);
    }
    if(x==1)
    {
        cout<<'1'<<' ';
        ans++;
    }
    else if(k==0)
    {
        cout<<x<<' ';
        ans++;
    }
    else
    {
        ll bz=m[x];
        // debug(k);
        // debug(bz);
        for(auto z:v[bz])
        {
            find(z,k-1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll x,k;
    cin>>x>>k;
    if(x==1)
    {
        cout<<"1";
        return 0;
    }
    m[x]=0;
    for(ll i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            v[0].pb(i);
            if(i!=x/i)
            {
                v[0].pb(x/i);
            }
        }
    }
    sort(all(v[0]));
    for(auto z:v[0])
    {
        if(z==x)
        {
            break;
        }
        ll zz=m.size();
        m[z]=zz;
        for(ll i=1;i*i<=z;i++)
        {
            if(z%i==0)
            {
                v[zz].pb(i);
                if(i!=z/i)
                {
                    v[zz].pb(z/i);
                }
            }    
        }
        sort(all(v[zz]));
    }
    // debug(x);
    find(x,k);
    return 0;
}