#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1111;

int n, m, k;
vector<int> adj[N];
vector<int> s;
int visit[N];

int dfs(int u) {
	if (visit[u]) return 0;
	int ret = visit[u] = 1;
	for (auto v : adj[u]) {
		ret += dfs(v);
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int v;
		scanf("%d", &v);
		s.push_back(v - 1);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ss;
	for (auto v : s) {
		int sv = dfs(v);
		ss.push_back(sv);
	}
	sort(ss.begin(), ss.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) if (!visit[i]) {
		cnt += dfs(i);
	}
	reverse(ss.begin(), ss.end());
	ss[0] += cnt;
	int tot = 0;
	for (int i = 0; i < ss.size(); i++) {
		tot += ss[i] * (ss[i] - 1) / 2;
	}
	printf("%d\n", tot - m);
	return 0;
}