#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

const int N = 100100;
int n, a[N], b[N];

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];

	vector<int> v[2];
	rep(i, 1, n) v[a[i]].push_back(b[i]);

	sort(v[0].begin(), v[0].end());
	reverse(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	reverse(v[1].begin(), v[1].end());

	int bonus = min(v[0].size(), v[1].size());
	ll res = 0;

	rep(i, 0, bonus - 1) {
		res += v[0][i];
		res += v[1][i];
	}

	if (v[0].size() == v[1].size()) {
		res -= min(*v[0].rbegin(), *v[1].rbegin());
	}

	cout << res + accumulate(b + 1, b + n + 1, 0ll) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}