#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[15][2020];
int B[15][15];
int N, M;

vector<pii> v;
int D[15][5050];
int sft[5050][15];
int sum[15][5050];

int f(int x) {
	int t = 0;
	if(x & (1 << (N - 1))) t = 1;
	return ((x << 1) & ((1 << N) - 1)) | t;
}

void init(int r, int n, int b, int s) {
	if(n >= N) {
		sum[r][b] = s;
		return;
	}
	init(r, n + 1, b, s);
	init(r, n + 1, b | (1 << n), s + B[n][r]);
}

int main() {
	int T; scanf("%d", &T);

	while(T--) {
		v.clear();
		scanf("%d%d", &N, &M);

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				scanf("%d", &A[i][j]);
			}
		}

		for(int i = 1; i <= M; i++) {
			int mx = 0;
			for(int j = 1; j <= N; j++) mx = max(mx, A[j][i]);
			v.push_back({mx, i});
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		M = min(M, N);

		for(int i = 0; i < M; i++) {
			for(int j = 1; j <= N; j++) {
				B[j - 1][i] = A[j][v[i].second];
			}
		}

		// for(int i = 0; i < N; i++) {
		// 	for(int j = 0; j < N; j++) {
		// 		printf("%d ", B[i][j]);
		// 	}
		// 	puts("");
		// }

		for(int i = 0; i < (1 << N); i++) sft[i][0] = i;
		for(int i = 1; i < N; i++) {
			for(int j = 0; j < (1 << N); j++) sft[j][i] = f(sft[j][i - 1]);
		}

		for(int i = 0; i < M; i++) init(i, 0, 0, 0);

		for(int i = 0; i < (1 << N); i++) D[0][i] = sum[0][i];

		for(int i = 1; i < M; i++) {
			for(int j = 0; j < (1 << N); j++) {
				D[i][j] = D[i - 1][j];
				for(int t = 0; t < N; t++) {
					for(int k = j; k; k = (k - 1) & j) {
						D[i][j] = max(D[i][j], D[i - 1][j ^ k] + sum[i][sft[k][t]]);
					}
				}
			}
		}
		printf("%d\n", D[M - 1][(1 << N) - 1]);

		for(int i = 0; i < M; i++) {
			for(int j = 0; j < (1 << N); j++) D[i][j] = 0;
		}
	}

	return 0;
}