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
    ll n;
    cin>>n;
    ll ans=0;
    ll ar[n];
    rep(i,n)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    for(ll i=0;i<n/2;i++)
    {
        ans+=(ar[i]+ar[n-1-i])*(ar[i]+ar[n-1-i]);
    }
    cout<<ans;
    return 0;
}