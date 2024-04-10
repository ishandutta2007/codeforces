//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;

		vector<int> a(n);
		for (auto &x : a)
			cin >> x;

		int res = 0;
		rep(i, 0, n)
			rep(j, i + 1, n)
				res += a[i] < a[j];
		cout << res << '\n';
	}
	return 0;
}