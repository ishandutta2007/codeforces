#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, A, B;
vector<int> adj[202020];
bool vst[202020];
bool vst2[202020];
int cnt;

void dfs1(int v) {
	vst[v] = true;
	for(int i : adj[v]) {
		if(i == A || vst[i]) continue;
		dfs1(i);
	}
}

void dfs2(int v) {
	vst2[v] = true;
	cnt++;
	for(int i : adj[v]) {
		if(i == B || !vst[i] || vst2[i]) continue;
		dfs2(i);
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &N, &M, &A, &B);
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs1(B);

		cnt = 0;
		for(int i = 1; i <= N; i++) if(!vst[i]) cnt++;
		cnt--;

		ll ans = cnt;
		cnt = 0;

		dfs2(A);
		ans = ans * (N - ans - cnt - 1);
		printf("%lld\n", ans);

		for(int i = 1; i <= N; i++) { adj[i].clear(); vst[i] = vst2[i] = false; }
	}

	return 0;
}