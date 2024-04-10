#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > A;
vector<vector<int> > C;

int P[1010101];
vector<int> rev[1010101];
char s[1010101];
bool vst[1010101];
bool iscycle[1010101];

vector<int> cyc;
int id[1010101];
int B[1010101];
int cycn;

int N, M;

int dfs(int v) {
	vst[v] = true;
	if(vst[P[v]]) {
		cyc.push_back(v);
		return P[v];
	}
	int t = dfs(P[v]);
	if(t) cyc.push_back(v);
	if(t == v) return 0;
	else return t;
}

void dfs2(int v, int p, int c) {
	vst[v] = true;

	int x = (v - 1) / M + 1;
	int y = (v - 1) % M + 1;
	B[c] |= C[x][y];

	for(int i : rev[v]) {
		if(i == p || iscycle[i]) continue;
		dfs2(i, v, (c + 1) % cycn);
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		A.resize(N + 1);
		C.resize(N + 1);
		for(int i = 1; i <= N; i++) {
			A[i].resize(M + 1);
			C[i].resize(M + 1);
		}

		for(int i = 1; i <= N; i++) {
			scanf("%s", s + 1);
			for(int j = 1; j <= M; j++) {
				C[i][j] = 1 - (s[j] - '0');
			}
		}

		for(int i = 1; i <= N; i++) {
			scanf("%s", s + 1);
			for(int j = 1; j <= M; j++) {
				if(s[j] == 'U') A[i][j] = -M;
				if(s[j] == 'D') A[i][j] = M;
				if(s[j] == 'L') A[i][j] = -1;
				if(s[j] == 'R') A[i][j] = 1;
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int idx = (i - 1) * M + j;
				P[idx] = idx + A[i][j];
				rev[idx + A[i][j]].push_back(idx);
			}
		}

		int ans1 = 0, ans2 = 0;
		for(int i = 1; i <= N * M; i++) {
			if(vst[i]) continue;
			dfs(i);

			cycn = cyc.size();
			ans1 += cycn;

			for(int j = 0; j < cycn; j++) B[j] = 0;
			for(int j : cyc) iscycle[j] = true;

			for(int j = 0; j < cycn; j++) {
				dfs2(cyc[j], 0, j);
			}

			for(int j = 0; j < cycn; j++) ans2 += B[j];

			cyc.clear();
		}
		printf("%d %d\n", ans1, ans2);

		for(int i = 1; i <= N * M; i++) {
			rev[i].clear();
			vst[i] = iscycle[i] = false;
		}
		A.clear(); C.clear();
	}
	return 0;
}