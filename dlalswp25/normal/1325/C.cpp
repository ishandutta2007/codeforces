#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > adj[101010];
int N;
int ans[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}

	for(int i = 1; i < N; i++) ans[i] = -1;

	int c = 0;
	for(int i = 1; i <= N; i++) {
		if(adj[i].size() >= 3) {
			for(auto j : adj[i]) {
				ans[j.second] = c;
				c++;
			}
			break;
		}
	}

	for(int i = 1; i < N; i++) {
		if(ans[i] != -1) continue;
		ans[i] = c; c++;
	}

	for(int i = 1; i < N; i++) printf("%d\n", ans[i]);
	return 0;
}