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

const int INF = 1e9 + 7, M = 1e9 + 7, N = 2e5 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

namespace bit {
	int bit[N];

	void add(int pos, int val) {
		pos++;
		for(; pos < N; pos += pos & -pos)
			::add(bit[pos], val);
	}

	int qry(int pos) {
		pos++;
		int res = 0;
		for(; pos; pos -= pos & -pos)
			::add(res, bit[pos]);
		return res;
	}
}

void solve() {
	int n; cin >> n;
	vi a(n), pos(n), aux(n);
	V<pi> compress;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		compress.EB(a[i], -i);
	}
	sort(ALL(compress));
	for(int i = 0; i < n; i++) {
		a[i] = int(lower_bound(ALL(compress), MP(a[i], -i)) - compress.begin());
		pos[a[i]] = i;
	}
	V<bool> special(n);
	int mx = -1;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] > mx) {
			special[a[i]] = true;
			mx = a[i];
		}
	}
	vi b = a, t;
	sort(ALL(b));
	for(int i = 0; i < n; i++) {
		t.PB(b[i]);
		if(special[b[i]]) {
			sort(ALL(t), [&](int x, int y) {
				return pos[x] > pos[y];
			});
			assert(t[0] == b[i]);
			V<pi> undo;
			for(int j:t) {
				int ways = (bit::qry(n) - bit::qry(j) + M + (j == b[i])) % M;
				bit::add(j, ways);
				undo.EB(j, ways);
				add(aux[j], M - ways);
			}
			for(auto[x, y]:undo)
				bit::add(x, M - y);
			t.clear();
		} 
	}
	b = a;
	reverse(ALL(b));
	V<pi> undo;
	for(int j:b) {
		int ways = (bit::qry(n) - bit::qry(j) + M + 1) % M;
		bit::add(j, ways);
		undo.EB(j, ways);
		add(aux[j], ways);
	}
	for(auto[x, y]:undo)
		bit::add(x, M - y);

	int ans = 0;
	vi dp(n);
	for(int i:a) {
		dp[i] = (bit::qry(i) + 1) % M;
		bit::add(i, dp[i]);
		debug(i, dp[i], aux[i]);
		add(ans, int(1LL * aux[i] * dp[i] % M));
	}
	for(int i:a) bit::add(i, M - dp[i]);
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