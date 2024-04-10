#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << "\n";
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

int n, k, a[200200];

void solve() {
	cin >> n >> k;
	map<int, int> m;
	rep(i, 1, n) {
		cin >> a[i];
		m[a[i]]++;
	}
	bool res = 0;
	rep(i, 1, n) {
		int x = a[i];
		if (!m.count(k + x)) continue;
		if (m[k + x] > (0 + ((k + x) == x)))
			res = 1;
	}
	cout << (res ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

    return 0;
}