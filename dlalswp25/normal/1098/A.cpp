#include <bits/stdc++.h>

using namespace std;

int p[100005];
int s[100005];
vector<int> adj[100005];
long long ans;

void dfs(int now, int par, int d) {
	if(ans == -1) return;

	if(d & 1) {
		for(int i : adj[now]) {
			if(i == par) continue;
			dfs(i, now, d + 1);
		}
	}
	else {
		if(adj[now].size() == 1) return;
		
		int ps = s[par];
		int m = 1000000005;
		for(int i : adj[now]) {
			if(i == par) continue;
			m = min(m, s[i] - ps);
		}
		if(m < 0) { ans = -1; return; }

		ans += m;
		for(int i : adj[now]) {
			if(i == par) continue;
			ans += s[i] - ps - m;
		}
		for(int i : adj[now]) {
			if(i == par) continue;
			dfs(i, now, d + 1);
		}
	}
}

int main() {
	int N; scanf("%d", &N);
	for(int i = 2; i <= N; i++) {
		scanf("%d", &p[i]);
		adj[i].push_back(p[i]);
		adj[p[i]].push_back(i);
	}
	for(int i = 1; i <= N; i++) scanf("%d", &s[i]);
	ans = s[1];

	dfs(1, 0, 1);
	printf("%lld\n", ans);
	return 0;
}