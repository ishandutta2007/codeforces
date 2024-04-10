#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

const int nn = 1 << 19;

vector<pii> g[nn];
vector<int> d;
vector<int> used;
vector<int> visited;

int dfs(int v, int p) {
	int sum = (d[v] == 1);
	visited[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int z = g[v][i].first;
		if (visited[z] == true) continue;
		int need = dfs(z, v);
		if (need) {
			used[g[v][i].second] = 1;
			sum += 1;
		}
	}
	return sum % 2;
}

bool solve() {
	int n, m; cin >> n >> m;
	d.resize(n);
	for (int i = 0; i < n; ++i) cin >> d[i];
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		--x; --y;
		g[x].push_back(pii(y, i));
		g[y].push_back(pii(x, i));
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) if (d[i] == 1) ++cnt;
	for (int i = 0; i < n; ++i) if (d[i] == -1 && cnt % 2 == 1) {
		d[i] = 1; cnt++;
	}

	if (cnt % 2 == 1) {
		cout << -1 << endl; return false;
	}

	visited.resize(n);
	used.resize(m);
	dfs(0, -1);

	cout << count(used.begin(), used.end(), 1) << endl;
	for (int i = 0; i < m; ++i) {
		if (used[i]) cout << i + 1 << '\n';
	}

    return false;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
    while (solve());
    
    return 0;
}