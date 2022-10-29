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

ll a[100005];
ll b[100005];
pair<ll, ll> c[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,k;
    cin>>n>>k;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,n){
    	cin>>b[i];
    }
    rep(i,n){
    	c[i] = mp(a[i],b[i]);
    }
    sort(c, c+n);
    c[n] = mp(0,0);
    ll sum = 0;
    vector<ll> v;
    ll count = 0;
    rep(i,n){
    	if(c[i].ff == c[i+1].ff){
    		v.pb(c[i].ss);
    	}
    	else{
    		count++;
    	}
    }
    sort(v.begin(), v.end());
    ll req = k - count;
    // debug(k);
    // debug(count);
    rep(i,req){
    	sum+=v[i];
    }
    cout<<sum;
}