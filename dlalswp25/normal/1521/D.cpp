#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int D[101010];
int E[101010];
int PD[101010];
int PE1[101010];
int PE2[101010];

vector<int> adj[101010];
int par[101010];
bool chk[101010];
vector<pii> chains;
vector<pii> ers;

void dfs(int v, int p) {
	par[v] = p;
	vector<pii> delta;
	int sum = 0;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		delta.emplace_back(D[i] - E[i], i);
		sum += E[i];
	}
	sort(delta.begin(), delta.end());
	D[v] = E[v] = sum + 1;
	if(delta.size() >= 1) {
		if(D[v] > sum + delta[0].first) {
			E[v] = D[v] = sum + delta[0].first;
			PE1[v] = PD[v] = delta[0].second;
		}
	}
	if(delta.size() >= 2) {
		int t = sum + delta[0].first + delta[1].first - 1;
		if(E[v] > t) {
			E[v] = t;
			PE1[v] = delta[0].second;
			PE2[v] = delta[1].second;
		}
	}
}

void dfs2(int v, int p, bool isD) {
	if(isD) {
		for(int i : adj[v]) {
			if(i == p) continue;
			if(i == PD[v]) {
				chk[i] = true;
				dfs2(i, v, true);
			}
			else dfs2(i, v, false);
		}
	}
	else {
		for(int i : adj[v]) {
			if(i == p) continue;
			if(i == PE1[v] || i == PE2[v]) {
				chk[i] = true;
				dfs2(i, v, true);
			}
			else dfs2(i, v, false);
		}
	}
}

int dfs3(int v, int p, bool rt) {
	int a = 0, b = 0;
	for(int i : adj[v]) {
		if(i == p || !chk[i]) continue;
		int t = dfs3(i, v, false);
		if(!a) a = t;
		else b = t;
	}
	if(!a) a = v;
	if(!b) b = v;
	// printf("%d %d %d\n", v, a, b);
	if(rt) chains.emplace_back(a, b);
	for(int i : adj[v]) {
		if(i == p || chk[i]) continue;
		dfs3(i, v, true);
	}
	return a;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			adj[i].clear();
			D[i] = E[i] = PD[i] = PE1[i] = PE2[i] = par[i] = 0;
			chk[i] = false;
		}
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs(1, 0);
		int ans = E[1] - 1;
		dfs2(1, 0, false);

		chains.clear();
		dfs3(1, 0, true);

		// for(int i = 1; i <= N; i++) printf("%d ", D[i]); puts("");
		// for(int i = 1; i <= N; i++) printf("%d ", E[i]); puts("");
		// for(int i = 1; i <= N; i++) printf("%d ", chk[i]); puts("");

		ers.clear();
		for(int i = 2; i <= N; i++) if(!chk[i]) { ers.emplace_back(i, par[i]); }
		printf("%d\n", ans);
		// for(pii i : chains) printf("%d %d\n", i.first, i.second);
		assert(chains.size() == ans + 1);
		assert(ers.size() == ans);
		for(int i = 0; i < ans; i++) {
			printf("%d %d %d %d\n", ers[i].first, ers[i].second, chains[i].second, chains[i + 1].first);
		}
	}
	return 0;
}