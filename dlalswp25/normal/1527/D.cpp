#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int sz[202020];
int dfn[202020];
int ed[202020];
ll ans[202020];
vector<int> adj[202020];
int id;

void dfs(int v, int p) {
	sz[v] = 1;
	dfn[v] = ++id;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
	}
	ed[v] = id;
}

bool isParent(int v, int p) {
	return dfn[p] <= dfn[v] && dfn[v] <= ed[p];
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			a++; b++;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		id = 0;
		dfs(1, 0);

		int x;

		ll t = 0;
		ll S = (ll)N * (N - 1) / 2;
		for(int i : adj[1]) {
			t += (ll)sz[i] * (sz[i] - 1) / 2;
			if(isParent(2, i)) x = i;
		}

		int A = 2, B = 0;
		ans[1] = t;
		ans[2] = S - (ll)sz[A] * (N - sz[x]);

		for(int i = 3; i <= N; i++) {
			ans[i] = S;
			if(!A) continue;
			if(isParent(i, A)) A = i;
			else if(isParent(A, i)) {}
			else {
				if(!B) {
					if(isParent(i, x)) A = 0;
					else B = i;
				}
				else {
					if(isParent(i, B)) B = i;
					else if(isParent(B, i)) {}
					else A = 0;
				}
			}
			if(!B) ans[i] -= (ll)sz[A] * (N - sz[x]);
			else ans[i] -= (ll)sz[A] * sz[B];
		}
		ans[N + 1] = S;

		for(int i = N + 1; i >= 2; i--) ans[i] -= ans[i - 1];
		for(int i = 1; i <= N + 1; i++) printf("%lld ", ans[i]); puts("");
	}
	return 0;
}