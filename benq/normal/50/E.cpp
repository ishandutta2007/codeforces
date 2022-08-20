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

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,m; cin >> n >> m;
	vector<pii> posi;
	for (ll b = 1; b <= n; ++b) {
		if (m >= b*b) {
			posi.pb(mp(-2*b+1,-1));
			ans += 2*(b*b-b);
			// cout << "HI\n" << ans << "\n";
		} else {
			// under the square root: b*b-m to b*b-1
			int k = ceil(sqrt(b*b-m)); // k to b-1
			posi.pb(mp(-b+k,-1));
			posi.pb(mp(-2*b+1,-b-k));
			ans += 2*(m-(b-k));
		}
	}
	sort(posi.begin(),posi.end());
	F0R(i,posi.size()) {
		int low = posi[i].f, high = posi[i].s;
		// cout << low << " " << high << "\n";
		while (i<posi.size()-1 && posi[i+1].f <= high) 
		    high = max(high,posi[++i].s);
		// cout << low << " " << high << "\n";
		ans += (high-low+1);
	}
	cout << ans << "\n";
	// b from 1 to n
	// c from 1 to m
	// -b +- sqrt(b^2-c)
}