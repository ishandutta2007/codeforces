#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 1 << 18;

int n[N], m, vis[N], ID, sz[N], take[N];
vector<pair<int, int>> e[N];
vector<int> euler;
map<int, int> mp;
map<pair<int, int>, int> cnt;

int id(int x) {
	if (mp.count(x))
		return mp[x];
	return mp[x] = m + ++ID;
}

void dfs(int u, int last) {
	while (!e[u].empty()) {
		auto [v, id] = e[u].back();
		e[u].pop_back();
		if (vis[id])
			continue;
		vis[id] = 1;
		dfs(v, id);
	}
	euler.push_back(last);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int c = 0;
	cin >> m;
	rep(i, 1, m) {
		sz[i] = c;
		cin >> n[i];
		rep(j, 1, n[i]) {
			int x;
			cin >> x;
			x = id(x);
			c++;
			e[x].push_back({i, c});
			e[i].push_back({x, c});
		}
	}

	rep(i, 1, m + ID) 
		if (e[i].size() % 2 == 1) {
			cout << "NO\n";
			return 0;
		}

	rep(i, 1, m + ID) {
		euler.clear();
		dfs(i, -1);
		assert(euler.size() % 2 == 1);
		for (int j = 1; j < int(euler.size()); j += 2)
			take[euler[j]] = 1;
	}

	cout << "YES\n";
	rep(i, 1, m) {
		rep(j, 1, n[i])
			cout << (take[sz[i] + j] ? "L" : "R");
		cout << endl;
	}

	return 0;
}