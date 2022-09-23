#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int sz[505050];
int S[505050];
int up[505050];
int L[505050];
int top[505050];
int C[505050];
vector<pii> adj[505050];
vector<int> ch[505050];

void dfs(int v, int p, int c) {
	C[v] = c;
	if(c) {
		up[v] = L[c];
		ch[L[c]].push_back(v);
	}
	int tmp = L[c];
	L[c] = v;
	sz[v] = 1;
	for(pii i : adj[v]) {
		if(i.first == p) continue;
		dfs(i.first, v, i.second);
		sz[v] += sz[i.first];
	}
	S[v] = sz[v];
	for(int i : ch[v]) S[v] -= sz[i];
	L[c] = tmp;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	dfs(1, 0, 0);
	for(int i = 1; i <= N; i++) top[i] = N;
	for(int i = 1; i <= N; i++) {
		if(!up[i]) {
			top[C[i]] -= sz[i];
		}
	}
	ll ans = 0;
	for(int i = 2; i <= N; i++) {
		ans += (ll)S[i] * (up[i] ? S[up[i]] : top[C[i]]);
	}
	printf("%lld\n", ans);
	return 0;
}