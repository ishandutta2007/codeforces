#include <bits/stdc++.h>

using namespace std;

int mx;
vector<int> adj[101010];
int N;

vector<pair<int, int> > ans;

void dfs(int v, int p, int c) {
	int cur = c;
	ans.push_back({v, cur});

	int rem = (int)adj[v].size() - 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		if(cur == mx) {
			cur = c - 1 - rem;
			ans.push_back({v, cur});
		}
		dfs(i, v, cur + 1);
		cur += 1;
		ans.push_back({v, cur});
		rem--;
	}
	if(v != 1 && cur != c - 1) ans.push_back({v, c - 1});
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) mx = max(mx, (int)adj[i].size());
	// printf("%d\n", mx);

	dfs(1, 0, 0);

	printf("%d\n", ans.size());
	for(auto i : ans) printf("%d %d\n", i.first, i.second);

	return 0;
}