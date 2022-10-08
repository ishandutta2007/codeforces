/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, m, a, b;
		cin >> n >> m;
		vector<vector<int>> g(n);
		while (m--) {
			cin >> a >> b;
			g[--a].push_back(--b);
		}

		vector<int> d(n, -1), q;
		auto add = [&](int v, int D) {
			if (d[v] == -1)
				d[v] = D, q.push_back(v);
		};
		add(0, 0);
		for (size_t i = 0; i < q.size(); i++) {
			int v = q[i];
			for (int x : g[v])
				add(x, d[v] + 1);
		}

		vector<int> ans = d;
		reverse(all(q));
		for (int v : q)
			for (int x : g[v])
				ans[v] = min(ans[v], d[x] > d[v] ? ans[x] : d[x]);

		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
}