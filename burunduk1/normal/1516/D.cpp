/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int M = 1e5 + 1;

int main() {
	vector<int> d(M), last(M, -1);
	for (int i = 2; i < M; i++)
		for (int j = i; j < M; j += i)
			if (!d[j])
				d[j] = i;

	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> next(n, n);
	forn(i, n) {
		int x;
		cin >> x;
		while (x > 1) {
			int y = d[x];
			while (x % y == 0)
				x /= y;
			int &p = last[y];
			auto relaxMin = [&](int &a, int b) { a = min(a, b); };
			if (p != -1)
				relaxMin(next[p], i);
			p = i;
		}
	}

	vector<int> dp(n + 1, n);
	for (int i = n - 1; i >= 0; i--)
		dp[i] = min(next[i], dp[i + 1]);

	const int K = 20;
	vector<vector<int>> go(K, vector<int>(n + 1, n));
	go[0] = dp;
	for (int k = 1; k < K; k++)
		forn(i, n)
			go[k][i] = go[k - 1][go[k - 1][i]];

	while (q--) {
		int l, r, ans = 0;
		cin >> l >> r, l--;
		for (int k = K - 1; k >= 0; k--)
			if (go[k][l] < r)
				l = go[k][l], ans += 1 << k;
		cout << ans + 1 << "\n";
	}
}