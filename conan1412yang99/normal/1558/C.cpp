#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] % 2 != i % 2) {
			cout << -1 << '\n';
			return;
		}
	}
	vi ans;
	auto rev = [&] (int p) {
		assert(p % 2 == 1);
		assert(p <= n);
		ans.PB(p);
		reverse(a.begin() + 1, a.begin() + p + 1);
	};

	for(int i = n; i > 1; i -= 2) {
		// i and i - 1
		assert(i & 1);
		int pos1 = find(ALL(a), i) - a.begin();
		rev(pos1);
		int pos2 = find(ALL(a), i - 1) - a.begin();
		rev(pos2 - 1);
		rev(pos2 + 1);
		rev(3);
		rev(i);
	}
	assert(is_sorted(ALL(a)));
	cout << ans.size() << '\n';
	for(int i:ans)
		cout << i << ' ';
	cout << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}