#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
ll A[202020];
int C[202020];

vector<int> adj[202020];
bool vst[202020];
bool bi;

void dfs(int v) {
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) {
			if(C[i] == C[v]) bi = false;
		}
		else {
			C[i] = 1 - C[v];
			dfs(i);
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();

		for(int i = 1; i <= N; i++) {
			scanf("%lld", &A[i]); A[i] *= -1;
		}
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a); A[i] += a;
		}

		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		ll s = 0;
		for(int i = 1; i <= N; i++) s += A[i];
		if(s & 1) { puts("NO"); continue; }

		for(int i = 1; i <= N; i++) vst[i] = false;
		bi = true;

		C[1] = 1; dfs(1);

		if(bi) {
			ll t = 0;
			for(int i = 1; i <= N; i++) if(C[i] == 1) t += A[i];
			if(s == 2 * t) puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
	return 0;
}