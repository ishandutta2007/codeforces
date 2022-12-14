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

int C2(int n) {
	return n * (n - 1) / 2;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi vis(2 * n);
	V<array<int, 2>> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i][0]--, a[i][1]--;
		vis[a[i][0]] = vis[a[i][1]] = 1;
	}
	auto intersect = [&] (int i, int j) {
		V<pi> v;
		v.EB(a[i][0], i);
		v.EB(a[i][1], i);
		v.EB(a[j][0], j);
		v.EB(a[j][1], j);
		sort(ALL(v));
		return v[0].S != v[1].S && v[1].S != v[2].S;
	};
	auto go = [&] (int l, int r) {
		assert(l != r);
		if((l + 1) % (n * 2) == r) return 0;
		if(l > r) r += n * 2;
		int ans = 0;
		for(int i = l + 1; i < r; i++) {
			if(vis[i % (n * 2)] == 0)
				ans++;
		}
		return ans;
	};
	int ans = C2(n - k);
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < i; j++) {
			if(intersect(i, j))
				ans++;
		}
		ans += min(go(a[i][0], a[i][1]), go(a[i][1], a[i][0]));
	}
	cout << ans << '\n';
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