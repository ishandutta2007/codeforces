#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101;

int N, M;
vector<int> A[505050];
vector<int> mxu[505050];
vector<int> mxd[505050];
vector<int> mnu[505050];
vector<int> mnd[505050];
char ans[505050];
int perm[505050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i <= N + 1; i++) {
			A[i].resize(M + 1);
			mxu[i].resize(M + 1);
			mxd[i].resize(M + 1);
			mnu[i].resize(M + 1);
			mnd[i].resize(M + 1);
		}
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
		}

		for(int i = 1; i <= N; i++) perm[i] = i;
		sort(perm + 1, perm + N + 1, [&](const int a, const int b) {
			return A[a][1] < A[b][1];
		});

		for(int j = 1; j <= M; j++) {
			mxu[0][j] = 0; mnu[0][j] = INF;
			mxd[N + 1][j] = 0; mnd[N + 1][j] = INF;
			for(int i = 1; i <= N; i++) {
				mxu[i][j] = max(mxu[i - 1][j], A[perm[i]][j]);
				mnu[i][j] = min(mnu[i - 1][j], A[perm[i]][j]);
			}
			for(int i = N; i >= 1; i--) {
				mxd[i][j] = max(mxd[i + 1][j], A[perm[i]][j]);
				mnd[i][j] = min(mnd[i + 1][j], A[perm[i]][j]);
			}
		}

		int l = -INF, r = INF;
		bool ok = true;
		for(int j = 1; j <= M; j++) {
			if(A[perm[1]][j] < A[perm[N]][j]) {
				l = max(l, j);
			}
			else if(A[perm[1]][j] > A[perm[N]][j]) {
				r = min(r, j);
			}
			else ok = false;
		}

		if(!ok || l + 1 != r) {
			puts("NO"); continue;
		}

		bool fin = false;
		for(int i = 1; i < N; i++) {
			ok = true;
			int mn = INF, mx = 0;
			for(int j = 1; j <= l; j++) {
				mn = min(mn, mnd[i + 1][j]);
				mx = max(mx, mxu[i][j]);
			}
			if(mn <= mx) ok = false;
			mn = INF; mx = 0;
			for(int j = l + 1; j <= M; j++) {
				mn = min(mn, mnu[i][j]);
				mx = max(mx, mxd[i + 1][j]);
			}
			if(mn <= mx) ok = false;
			if(ok) {
				for(int j = 1; j <= i; j++) ans[perm[j]] = 'B';
				for(int j = i + 1; j <= N; j++) ans[perm[j]] = 'R';
				puts("YES");
				for(int j = 1; j <= N; j++) printf("%c", ans[j]);
				printf(" %d\n", l);
				fin = true; break;
			}
		}

		if(!fin) puts("NO");
	}
	return 0;
}