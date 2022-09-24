#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> E;
ll A[202020], D[202020], D2[202020];
ll n, m;

void solve() {
	ll l, r, i, j, t;
	ll x, v1, v2;

	cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1); A[n + 1] = 1e18;
	E.clear();
	for (i = 1; i <= m; i++) {
		cin >> l >> r;
		j = lower_bound(A + 1, A + n + 1, l) - A;
		if (1 <= j && j <= n && l <= A[j] && A[j] <= r) continue;
		E.emplace_back(l, r);
	}
	sort(E.begin(), E.end());
	m = E.size();

	if (m == 0) {
		cout << "0\n";
		return;
	}

	fill(D, D + m + 1, 1e18);

	for (i = 1, j = 0; i <= n; i++) {
		for (l = j; l < m && E[l].second < A[i]; l++);

		if (l == j) v1 = v2 = D2[i - 1];
		else {
			x = A[i]; v1 = v2 = 1e18;
			for (t = l - 1; t >= j; t--) {
				v1 = min(v1, D[t] + (A[i] - x));
				v2 = min(v2, D[t] + (A[i] - x) * 2);
				x = min(x, E[t].second);
			}
			v1 = min(v1, D2[i - 1] + (A[i] - x));
			v2 = min(v2, D2[i - 1] + (A[i] - x) * 2);
		}
		D2[i] = min(v1, v2);

		if (l == m) {
			cout << D2[i] << "\n";
			return;
		}

		for (r = l; r < m && E[r].second < A[i + 1]; r++) {
			x = E[r].first;
			D[r] = min(v1 + (x - A[i]) * 2, v2 + (x - A[i]));
		}

		j = l;
	}

	cout << D[m - 1] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;

	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}