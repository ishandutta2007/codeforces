#include<bits/stdc++.h>
using namespace std;
 #include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;

// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
#define ll long long
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
 
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
 
 
ll pwr[32];
ll a1,b1;
vector<ll>v;
ll fn(ll a,ll b)
{
    std::vector<ll>::iterator low1, low2; 
    low1 = std::lower_bound(v.begin(), v.end(), a); 
    low2 = std::lower_bound(v.begin(), v.end(), b+1); 
    ll aa=(low1 - v.begin());
    ll bb=(low2 - v.begin());
    ll z=bb-aa;
    if(a==b)
    {
        if(z==0)
        return a1;
        else return b1*z;
    }
    else
    {
        if(z==0)
            return a1;
        else
        {
            ll k=(b-a+1)/2;
            return min(fn(a,a+k-1)+fn(a+k,b),z*b1*(b-a+1));
        }
    }

}
#define INF 1000000000000000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(11);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long double pi= 3.14159265358979323846;
    ll n,k;
    cin>>n>>k>>a1>>b1;
    
    rep(i,k)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    ll x=1;
    rep(i,32)
    {
        pwr[i]=x;
        x=x*2;
    }
    sort(v.begin(),v.end());
    cout<<fn(1,pwr[n]);
    return 0;
}