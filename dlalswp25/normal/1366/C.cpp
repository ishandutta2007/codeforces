#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[35][35];
int cnt[65];
int cnt1[65];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
		for(int i = 2; i <= N + M; i++) cnt[i] = cnt1[i] = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
			cnt[i + j]++;
			cnt1[i + j] += A[i][j];
		}

		int ans = 0;
		for(int i = 2; i < (N + M + 3) / 2; i++) {
			int t = (N + M - i) + 2;
			int tot = cnt[i] + cnt[t];
			int z = tot - (cnt1[i] + cnt1[t]);
			int o = tot - z;
			ans += min(z, o);
		}
		printf("%d\n", ans);
	}
	return 0;
}