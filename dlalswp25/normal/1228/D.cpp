#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<pii, int> mp;
vector<int> adj[101010];

int N, M;
int C[101010];
bool vst[101010];
ll sz[5];
int E[2][303030];

void init(int v) {
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) continue;
		init(i);
	}
}

bool exi(int a, int b) {
	auto it = mp.find({a, b});
	if(it != mp.end()) return true;
	it = mp.find({b, a});
	if(it != mp.end()) return true;
	return false;
}

void dfs(int v, int x) {
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) continue;
		if(exi(i, x)) C[i] = 6 - C[v] - C[x];
		else C[i] = C[x];
		dfs(i, v);
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		mp[{a, b}]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
		E[0][i] = a; E[1][i] = b;
	}

	init(1);
	for(int i = 1; i <= N; i++) {
		if(!vst[i]) { puts("-1"); return 0; }
		vst[i] = 0;
	}

	C[1] = 1; C[adj[1][0]] = 2;
	dfs(1, adj[1][0]);

	for(int i = 1; i <= M; i++) {
		int a = E[0][i], b = E[1][i];
		if(C[a] == C[b]) { puts("-1"); return 0; }
	}
	for(int i = 1; i <= N; i++) sz[C[i]]++;

	if(M != sz[1] * sz[2] + sz[2] * sz[3] + sz[3] * sz[1]) { puts("-1"); return 0; }
	if(sz[1] * sz[2] * sz[3] == 0) { puts("-1"); return 0; }
	for(int i = 1; i <= N; i++) printf("%d ", C[i]);

	return 0;
}