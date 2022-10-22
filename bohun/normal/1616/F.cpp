#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> id(n, vector<int>(n, -1));
		vector<vector<int>> eq;

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			if (a > b) swap(a, b);
			if (c > 0) {
				c--;
				vector<int> cur(m + 1);
				cur[i] = 1;
				cur[m] = c;
				eq.push_back(cur);
			}
			id[a][b] = i;
		}

		for (int a = 0; a < n; a++)
			for (int b = a + 1; b < n; b++)
				for (int c = b + 1; c < n; c++) {
					if (id[a][b] != -1 && id[a][c] != -1 && id[b][c] != -1) {
						vector<int> cur(m + 1);

						cur[id[a][b]] = 1;
						cur[id[a][c]] = 1;
						cur[id[b][c]] = 1;

						eq.push_back(cur);
					}
				}

		n = m;
		m = eq.size();
		int rank = 0;
		for (int c = 0; c < n; c++) {
			int id = rank;
			while (id < m && eq[id][c] == 0)
				id++;
			if (id == m)
				continue;
			swap(eq[rank], eq[id]);
			for (int r = rank + 1; r < m; r++) {
				if (eq[r][c] == 0)
					continue;
				int coef = eq[r][c] * (eq[rank][c] == 1 ? 1 : 2) % 3;
				for (int i = c; i <= n; i++)
					eq[r][i] = (eq[r][i] - coef * eq[rank][i] + 9) % 3;
			}
			rank++;
		}

		bool bad = 0;
		for (int i = rank; i < m; i++)
			if (eq[i][n] > 0)
				bad = 1;

		if (bad) {
			cout << "-1\n";
			continue;
		}

		vector<int> res(n);
		for (int j = rank - 1; 0 <= j; j--) {
			int i = 0;
			while (eq[j][i] == 0)
				i++;
			res[i] = eq[j][n];
			for (int k = i + 1; k < n; k++)
				res[i] = (res[i] - eq[j][k] * res[k] % 3 + 3) % 3;
			if (eq[j][i] == 2)
				res[i] = 2 * res[i] % 3;
		}

		for (int i = 0; i < n; i++)
			cout << res[i] + 1 << ' ';
		cout << '\n';
	}
	return 0;
}