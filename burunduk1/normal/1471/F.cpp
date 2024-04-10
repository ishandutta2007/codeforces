/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define read(T, a, n) vector<T> a(n); for (auto &z : a) cin >> z

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, m, cnt = 0;
		cin >> n >> m;
		vector<vector<int>> g(n);
		while (m--) {
			int a, b;
			cin >> a >> b, a--, b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vector<int> used(n), ans;
		function<void(int)> dfs = [&](int v) {
			used[v] = 2, cnt++;
			for (int x : g[v])
				if (used[x] == 2)
					used[v] = 1;
			if (used[v] == 2)
				ans.push_back(v);
			for (int x : g[v])
				if (!used[x])
					dfs(x);
		};
		dfs(0);
		if (cnt < n) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		sort(all(ans));
		cout << ans.size() << "\n";
		for (int v : ans)
			cout << v + 1 << " ";
		cout << "\n";
	}
}