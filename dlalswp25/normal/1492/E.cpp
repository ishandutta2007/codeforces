#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A[252525];
int ans[252525];
int C[252525];
vector<int> v;

void chk() {
	for(int i = 1; i <= N; i++) {
		int diff = 0;
		for(int j = 1; j <= M; j++) {
			if(ans[j] != A[i][j]) diff++;
		}
		if(diff > 2) return;
	}

	puts("Yes");
	for(int i = 1; i <= M; i++) printf("%d ", ans[i]); puts("");
	exit(0);
}

void chk2() {
	for(int i = 1; i <= N; i++) C[i] = 0;
	int col = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(!ans[j]) { col = j; continue; }
			if(ans[j] != A[i][j]) C[i]++;
		}
		if(C[i] > 2) return;
	}
	int t = 0;
	for(int i = 1; i <= N; i++) {
		if(C[i] < 2) continue;
		if(t && t != A[i][col]) return;
		t = A[i][col];
	}

	if(!t) t = 9876;
	ans[col] = t;
	puts("Yes");
	for(int i = 1; i <= M; i++) printf("%d ", ans[i]); puts("");
	exit(0);
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) A[i].resize(M + 1);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int r = 0;
	for(int i = 2; i <= N; i++) {
		int diff = 0;
		for(int j = 1; j <= M; j++) {
			if(A[1][j] != A[i][j]) diff++;
		}
		if(diff >= 5) { puts("No"); return 0; }
		if(diff >= 3) {
			for(int j = 1; j <= M; j++) {
				if(A[1][j] == A[i][j]) ans[j] = A[1][j];
				else v.push_back(j);
			}
			r = i;
			break;
		}
	}

	if(!r) {
		puts("Yes");
		for(int i = 1; i <= M; i++) printf("%d ", A[1][i]); puts("");
		return 0;
	}

	int X[6][4] = {
		{1, 1, r, r},
		{1, r, 1, r},
		{1, r, r, 1},
		{r, 1, 1, r},
		{r, 1, r, 1},
		{r, r, 1, 1}
	};

	if(v.size() == 4) {
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 4; j++) {
				ans[v[j]] = A[X[i][j]][v[j]];
			}
			chk();
		}
		puts("No");
		return 0;
	}

	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 3; j++) {
			ans[v[j]] = A[X[i][j]][v[j]];
		}
		chk();
	}

	int Y[6][3] = {
		{0, 1, r},
		{0, r, 1},
		{1, 0, r},
		{1, r, 0},
		{r, 0, 1},
		{r, 1, 0}
	};

	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 3; j++) {
			if(!Y[i][j]) ans[v[j]] = 0;
			else ans[v[j]] = A[Y[i][j]][v[j]];
		}
		chk2();
	}

	puts("No");
	return 0;
}