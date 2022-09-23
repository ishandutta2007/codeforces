#include <bits/stdc++.h>

using namespace std;

int B;
int N;
vector<int> adj[202020];
int ans[202020];
bool vst[202020];
bool chk[202020];
vector<int> vs[2];

void dfs(int v, int p, int d) {
	vs[d & 1].push_back(v);
	vst[v] = true;
	for(int i : adj[v]) {
		if(chk[i] || i == p) continue;
		dfs(i, v, d + 1);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		B = 1;
		while(B <= N) B <<= 1; B >>= 1;

		for(int i = 1; i <= N; i++) chk[i] = false;
		while(B >= 1) {
			vs[0].clear(); vs[1].clear();
			for(int i = 1; i <= N; i++) vst[i] = false;
			for(int i = 1; i <= N; i++) {
				if(!vst[i] && !chk[i]) dfs(i, 0, 0);
			}
			vector<int> v = (vs[0].size() > vs[1].size()) ? vs[0] : vs[1];
			for(int i = 0; i < min(B, N - B + 1); i++) {
				ans[v[i]] = B + i;
				chk[v[i]] = true;
			}
			B >>= 1;
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}