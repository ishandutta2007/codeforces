#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const ll INF = 1e18;

ll x,y,l,r;
vector<ll> vx, vy;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> x >> y >> l >> r;
	ll cx = 1;
	while (1) {
	    vx.pb(cx);
	    if (x > INF/cx+1) break;
	    else cx *= x;
	}
	ll cy = 1;
	while (1) {
	    vy.pb(cy);
	    if (y > INF/cy+1) break;
	    else cy *= y;
	}
	vector<ll> tmp; tmp.pb(l-1); tmp.pb(r+1);
	for (auto a: vx) for (auto b: vy) if (l <= a+b && a+b <= r) tmp.pb(a+b);
	sort(tmp.begin(),tmp.end());
	ll ans = 0;
	F0R(i,tmp.size()-1) ans = max(ans,tmp[i+1]-tmp[i]-1);
	cout << ans;
}

// read!
// ll vs. int!