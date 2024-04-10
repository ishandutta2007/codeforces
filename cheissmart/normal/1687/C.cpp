#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], b[N];
ll c[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];

	for(int i = 1; i <= n; i++)
		c[i] = c[i - 1] + a[i] - b[i];

	V<vi> aux(n + 1);
	V<bool> active(n + 1);
	set<int> s;

	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r, l--;
		aux[l].PB(r);
		aux[r].PB(l);
	}
	for(int i = 0; i <= n; i++)
		s.insert(i);

	function<void(int)> activate = [&] (int i) {
		if(active[i]) return;
		active[i] = true;
		s.erase(i);
		for(int j:aux[i]) if(active[j]) {
			int l = min(i, j), r = max(i, j);
			while(SZ(s)) {
				auto it = s.upper_bound(l);
				if(it == s.end() || *it >= r) break;
				activate(*it);
			}
		}
	};

	for(int i = 0; i <= n; i++)
		if(c[i] == 0)
			activate(i);

	if(s.empty()) cout << "YES\n";
	else cout << "NO\n";
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