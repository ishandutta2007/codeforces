#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define int long long

const int MAXN = 3e5;

vector <int> levels[MAXN];
vector <int> graph[MAXN];

int show[MAXN];
int par[MAXN];
int level[MAXN];

void dfs(int v) {
	cout << '(';
	for (auto u : graph[v]) {
		dfs(u);
	}
	cout << ')';
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int max_allowed = (n * (n - 1)) / 2;
	if (k > max_allowed) {
		cout << "Impossible" << endl;
		return 0;
	}

	int cur = max_allowed;

	set <pair <int, int> > vertexes;
	for (int i = 0; i < n; i++) {
		level[i] = i;		
	}
	for (int i = n - 1; i > 0; i--) {
		int offset = min(cur - k, level[i]);
		level[i] = i - offset;
		cur -= offset;
	}
	for (int i = 0; i < n; i++) {
		levels[level[i]].push_back(i);
	}
	for (int i = 1; i < n; i++) {
		if (level[i] > 0)
		graph[levels[level[i] - 1].back()].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (level[i] == 0) {
			dfs(i);
		}
	}
}