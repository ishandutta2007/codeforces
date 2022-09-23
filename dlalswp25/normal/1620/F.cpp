#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int INF = 1010101010;

int N;
int A[1010101];
int D[1010101][2];
int ans[1010101];
int path[1010101][2];

void update(int i1, int j1, int i2, int j2) {
	int a1 = j1 == 1 ? -A[i1] : A[i1];
	int a2 = j2 == 1 ? -A[i2] : A[i2];

	int l = min(a2, D[i2][j2]);
	int r = max(a2, D[i2][j2]);
	if(a1 >= l) {
		if(a1 >= r) {
			if(D[i1][j1] > l) {
				D[i1][j1] = l;
				path[i1][j1] = j2;
			}
		}
		else {
			if(D[i1][j1] > r) {
				D[i1][j1] = r;
				path[i1][j1] = j2;
			}
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 2; j++) D[i][j] = INF;
		}
		D[1][0] = D[1][1] = -INF;
		for(int i = 2; i <= N; i++) {
			// D[i][0]
			update(i, 0, i - 1, 0);
			update(i, 0, i - 1, 1);
			update(i, 1, i - 1, 0);
			update(i, 1, i - 1, 1);
		}

		if(D[N][0] == INF && D[N][1] == INF) { puts("NO"); continue; }
		int t;
		if(D[N][0] != INF) {
			ans[N] = A[N];
			t = 0;
		}
		else {
			ans[N] = -A[N];
			t = 1;
		}
		for(int i = N; i > 1; i--) {
			if(path[i][t]) ans[i - 1] = -A[i - 1];
			else ans[i - 1] = A[i - 1];
			t = path[i][t];
		}
		puts("YES");
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}