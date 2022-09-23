#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> adj[202020];
int H[202020];
int mx[202020];
ll ans;

void dfs(int v, int p) {
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		mx[v] = max(mx[v], mx[i]);
	}

	if(!p) {
		vector<int> tmp;
		for(int i : adj[v]) {
			if(i == p) continue;
			tmp.push_back(mx[i]);
		}
		tmp.push_back(0);
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		ans += (ll)H[v] + H[v] - tmp[0] - tmp[1];
		return;
	}

	if(mx[v] < H[v]) {
		ans += H[v] - mx[v];
		mx[v] = H[v];
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &H[i]);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int M = 0;
	for(int i = 1; i <= N; i++) M = max(M, H[i]);

	int rt = 0;
	for(int i = 1; i <= N; i++) {
		if(H[i] == M) { rt = i; break; }
	}
	dfs(rt, 0);

	printf("%lld\n", ans);
	return 0;
}