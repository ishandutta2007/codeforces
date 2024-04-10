#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<list>
using namespace std;
pair<int, int>dp[5005][5005]; int n, m, t, indeg[5005]; bool used[5005];
vector<pair<int, int>>y[5005]; vector<int>x[5005];
list<int>out;

//--------------------------------------------Topological Sort------------------------------------
void bfs2(int s, vector<int> X[]) {
	queue<int> Q2; Q2.push(s); used[s] = true;
	while (!Q2.empty()) {
		int u = Q2.front(); Q2.pop(); out.push_back(u);
		for (int i = 0; i < X[u].size(); i++) {
			int to = X[u][i]; indeg[to]--;
			if (indeg[to] == 0 && used[to] == false) { used[to] = true; Q2.push(to); }
		}
	}
}
vector<int> Tsort(int V, int E, vector<int> X[]) {
	for (int i = 0; i < V; i++) { indeg[i] = 0; }
	for (int u = 0; u < V; u++) {
		for (int i = 0; i < X[u].size(); i++) { int v = X[u][i]; indeg[v]++; }
	}
	for (int u = 0; u < V; u++) {
		if (indeg[u] == 0 && used[u] == false) { bfs2(u, X); }
	}
	vector<int> res;
	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
		res.push_back(*it);
	}
	return res;
}
int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) { long long a, b, c; cin >> a >> b >> c; a--; b--; x[a].push_back(b); y[a].push_back(make_pair(b, c)); }
	for (int i = 0; i <= n; i++) { for (int j = 0; j <= n; j++)dp[i][j] = make_pair(1999999999, -1); }
	vector<int>r = Tsort(n, m, x);
	dp[0][0] = make_pair(0, -1);
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (dp[r[i]][j].first == 1999999999)continue;
			for (int k = 0; k < y[r[i]].size(); k++) {
				int to = y[r[i]][k].first, cost = y[r[i]][k].second;
				if ((long long)(0LL + dp[r[i]][j].first + cost) > t)continue;

				dp[to][j + 1] = min(dp[to][j + 1], make_pair(dp[r[i]][j].first + cost, r[i]));
			}
		}
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++) { if (dp[n - 1][i].first != 1999999999)maxn = i; }
	vector<int>ret; int cy = n - 1, cx = maxn;
	while (cy != -1) {
		ret.push_back(cy); cy = dp[cy][cx].second; cx--;
	}
	reverse(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for (int i = 0; i < (int)ret.size(); i++) { if (i)cout << ' '; cout << ret[i] + 1; }cout << endl;
	return 0;
}