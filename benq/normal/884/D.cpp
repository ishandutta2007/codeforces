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

int n;
ll ans = 0;
multiset<ll> m;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int x; cin >> x;
	    m.insert(x);
	}
	if (m.size() % 2 == 0) {
	    ll a = *m.begin(); m.erase(m.begin());
	    ll b = *m.begin(); m.erase(m.begin());
	    ans += a+b;
	    m.insert(a+b);
	}
	while (m.size() > 1) {
	    ll a = *m.begin(); m.erase(m.begin());
	    ll b = *m.begin(); m.erase(m.begin());
	    ll c = *m.begin(); m.erase(m.begin());
	    ans += a+b+c;
	    m.insert(a+b+c);
	}
	cout << ans;
}

// read!
// ll vs. int!