#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> q;
char ans[105][105];
int q1[105][105];
int X[105];
int up[105];

int query1(int a, int b) {
	if(q1[a][b] != -1) return q1[a][b];
	printf("1 %d %d\n", a, b); fflush(stdout);
	int ret; scanf("%d", &ret);
	q1[a][b] = ret;
	q1[b][a] = 1 - ret;
	return ret;
}

int query2(int x) {
	printf("2 %d %d ", x, q.size());
	for(int i : q) printf("%d ", i);
	printf("\n"); fflush(stdout);
	q.clear();
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) q1[i][j] = -1;
		int M = 2;
		if(query1(0, 1)) { X[0] = 0; X[1] = 1; }
		else { X[0] = 1; X[1] = 0; }
		for(int i = 2; i < N; i++, M++) {
			if(query1(i, X[0])) {
				for(int j = M; j >= 1; j--) X[j] = X[j - 1];
				X[0] = i;
				continue;
			}
			if(query1(X[M - 1], i)) {
				X[M] = i;
				continue;
			}

			int l = 0, r = M - 2;
			while(l <= r) {
				int m = l + r >> 1;
				if(query1(X[m], i)) l = m + 1;
				else r = m - 1;
			}
			for(int j = M; j > r + 1; j--) X[j] = X[j - 1];
			X[r + 1] = i;
		}
		// for(int i = 0; i < N; i++) printf("%d ", X[i]); puts("");

		for(int i = 0; i < N; i++) up[i] = i;
		for(int i = 1; i < N; i++) {
			while(1) {
				int u = up[i];
				if(!u) break;
				for(int j = 0; j < u; j++) q.push_back(X[j]);
				int t = query2(X[i]);
				if(!t) break;
				for(int j = u; j <= i; j++) up[j] = up[u - 1];
			}
		}

		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) ans[i][j] = '0';
		for(int i = 0; i < N; i++) {
			for(int j = i; j < N; j++) {
				ans[X[i]][X[j]] = '1';
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = up[i]; j < i; j++) {
				ans[X[i]][X[j]] = '1';
			}
		}
		printf("3\n");
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) printf("%c", ans[i][j]);
			printf("\n");
		}
		fflush(stdout);
		int chk; scanf("%d", &chk);
		if(chk == -1) break;
	}
	return 0;
}