#include <bits/stdc++.h>

using namespace std;

int N, M;
int x, y, z;

vector<int> adj[5050];

int C[5050];
bool ok;

int cnt[2];
int dc;
int sz[10101];
int D[5050][5050];
bool chk[10101];

void dfs(int v, int c) {
	C[v] = dc * 2 + c;
	sz[dc * 2 + c]++;
	for(int i : adj[v]) {
		if(C[i] != -1) {
			if(C[i] % 2 == c % 2) ok = false;
		}
		else dfs(i, 1 - c);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &x, &y, &z);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if(y == 0) {
		if(M) puts("NO");
		else {
			puts("YES");
			for(int i = 1; i <= N; i++) {
				if(x) printf("1");
				else printf("3");
			}
			puts("");
		}
		return 0;
	}

	for(int i = 1; i <= N; i++) C[i] = -1;

	ok = true;
	for(int i = 1; i <= N; i++) {
		if(C[i] == -1) {
			dc++;
			dfs(i, 0);
		}
	}

	if(!ok) { puts("NO"); return 0; }

	for(int i = 1; i <= N; i++) D[0][i] = -1;

	for(int i = 1; i <= dc; i++) {
		for(int j = N; j >= 0; j--) {
			if(j >= sz[2 * i] && D[i - 1][j - sz[2 * i]] != -1) D[i][j] = 2 * i;
			else if(j >= sz[2 * i + 1] && D[i - 1][j - sz[2 * i + 1]] != -1) D[i][j] = 2 * i + 1;
			else D[i][j] = -1;
		}
	}

	if(D[dc][y] == -1) { puts("NO"); return 0; }

	// for(int i = 1; i <= N; i++) printf("%d ", C[i]); puts("");

	puts("YES");

	// for(int i = 0; i <= N; i++) {
	// 	for(int j = 1; j <= N; j++) {
	// 		printf("%d ", D[i][j]);
	// 	}
	// 	puts("");
	// }

	int now = y;
	for(int i = dc; i >= 1; i--) {
		chk[D[i][now]] = true;
		now -= sz[D[i][now]];
	}

	for(int i = 1; i <= N; i++) {
		if(chk[C[i]]) printf("2");
		else if(x) { printf("1"); x--; }
		else printf("3");
	}
	puts("");

	return 0;
}