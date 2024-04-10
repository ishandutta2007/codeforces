#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[202020];

int dep[202020];
int ans = N;

void init(int v, int p) {
	dep[v] = dep[p] + 1;

	for(int i : adj[v]) {
		if(i == p) continue;
		init(i, v);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dep[0] = -1;

	init(1, 0);

	int cnt[2] = {0, 0};
	for(int i = 1; i <= N; i++) cnt[dep[i] & 1]++;

	printf("%d\n", min(cnt[0], cnt[1]) - 1);

	return 0;
}