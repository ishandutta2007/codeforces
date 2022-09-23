#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[505][505];
int B[505][505];
int C[505][505];

int b[505];
int vst[505];
vector<int> adj[505];

int dfs(int v, int t) {
	if(vst[v] == t) return 0;
	vst[v] = t;
	for(int i : adj[v]) {
		if(!b[i] || dfs(b[i], t)) {
			b[i] = v; return 1;
		}
	}
	return 0;
}

int bmatch() {
	int ret = 0, t = 0;
	for(int i = 1; i <= N; i++) {
		t++; ret += dfs(i, t);
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) B[i][j] = (A[i][j] == 'B');

	int sum = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			C[i][j] = (B[i][j] + B[i + 1][j] + B[i][j + 1] + B[i + 1][j + 1]) & 1;
			sum += C[i][j];
		}
	}

	for(int i = 1; i < N; i++) {
		for(int j = 1; j < M; j++) {
			if(C[i][M] && C[N][j] && C[i][j]) {
				adj[i].push_back(j);
			}
		}
	}

	int t = bmatch();
	if(C[N][M] && (t & 1)) sum--;
	else if(!C[N][M] && (t & 1)) sum++;

	printf("%d\n", sum - t);

	return 0;
}