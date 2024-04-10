#include <bits/stdc++.h>
using namespace std;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 5;
int n, q, a[N], a1[N], op[N], x[N], y[N], k[N], b[N * 2];
bool ans[N];
int c[N];

inline void modify(int p, int x) {
	for (; p <= n; p += p & -p) {
		c[p] += x;
	}
}

inline int query(int p) {
	int res = 0;
	for (; p; p -= p & -p) {
		res += c[p];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double st = clock();
    
	cin >> n >> q;
	vector<int> px;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		px.push_back(a[i]);
	}

	for (int i = 1; i <= q; ++i) {
		cin >> op[i] >> x[i] >> y[i];
		if (op[i] == 2) {
			cin >> k[i];
		} else {
			px.push_back(y[i]);
		}
	}

	sort(px.begin(), px.end());
	px.erase(unique(px.begin(), px.end()), px.end());
	int m = px.size();

	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(px.begin(), px.end(), a[i]) - px.begin();
	}
	for (int i = 1; i <= q; ++i) {
		if (op[i] == 1) {
			y[i] = lower_bound(px.begin(), px.end(), y[i]) - px.begin();
		}
	}

	memset(ans, true, sizeof ans);
	double T = 0;

	while (clock() + T - st <= 2800) {
		double tmp = clock();

		for (int i = 0; i < m; ++i) {
			b[i] = rnd() & 1;
		}

		memset(c, 0, sizeof c);
		for (int i = 1; i <= n; ++i) {
			a1[i] = b[a[i]];
			if (b[a[i]]) {
				modify(i, 1);
			}
		}

		for (int i = 1; i <= q; ++i) {
			if (op[i] == 1) {
				if (a1[x[i]] != b[y[i]]) {
					modify(x[i], b[y[i]] - a1[x[i]]);
					a1[x[i]] = b[y[i]];
				}
			} else {
				int sum = query(y[i]) - query(x[i] - 1);
				ans[i] &= (sum % k[i] == 0);
			}
		}

		T = clock() - tmp;
	}

	for (int i = 1; i <= q; ++i) {
		if (op[i] == 2) {
			cout << (ans[i] ? "YES" : "NO") << "\n";
		}
	}
	
	return 0;
}