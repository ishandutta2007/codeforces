/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

ll x,y;
vector<ll> prim;

void fill() {
    ll x1 = x;
    for (ll i = 2; i*i <= x; ++i) if (x % i == 0) {
        while (x % i == 0) x /= i;
        prim.pb(i);
    }
    if (x > 1) prim.pb(x);
    x = x1;
}

ll get(ll x, ll y) {
    ll ans = 0;
    while (y > 0) {
        ll g = __gcd(x,y);
        x /= g, y /= g;
        ll mx = 0;
        for (ll a: prim) if (x % a == 0) mx = max(mx,a*(y/a));
        ans += (y-mx);
        y = mx;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> x >> y;
	fill();
	cout << get(x,y);
}