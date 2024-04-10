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

ll n,k,mx=-1;

int main() {
	cin >> n >> k;
	ll up = 2*n/k/(k+1);
	FOR(i,1,sqrt(n)+1) {
		if (n % i == 0) {
			if (i<=up) mx = max(mx,(ll)i);
			if (n/i<=up) mx = max(mx,n/i);
		}
	}
	vector<ll> ans;
	if (mx == -1) {
		cout << -1;
		return 0;
	}
	FOR(i,1,k) {
		ans.pb(i*mx);
		n -= i*mx;
	}
	ans.pb(n);
	for (auto a: ans) cout << a << " ";
}