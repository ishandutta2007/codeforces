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

bool solve() {
	int n, zero = -1;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
		if(a[i] == 0) zero = i;
	}
	if(zero != -1)
		return true;
	for(int i = 1; i < n; i++) {
		vi w(i), ws;
		bool ok = false;
		function<void(int, int)> dfs = [&] (int j, int sum) {
			if(j == i) {
				if(sum == a[i]) {
					ok = true;
					ws = w;
				}
				return;
			}
			w[j] = 0;
			dfs(j + 1, sum);
			w[j] = 1;
			dfs(j + 1, sum + a[j]);
			w[j] = -1;
			dfs(j + 1, sum - a[j]);
		};
		dfs(0, 0);
		if(ok)
			return true;
	}
	return false;
}


signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
	
}