#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int cnt[202];

vector<int> V[202];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);

		for(int i = 1; i <= 200; i++) V[i].clear();

		for(int i = 1; i <= 200; i++) V[i].push_back(0);

		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			V[A[i]].push_back(i);
		}

		for(int i = 1; i <= 200; i++) V[i].push_back(N + 1);

		int ans = 0;
		for(int i = 1; i <= 200; i++) {
			for(int j = 1; j <= 200; j++) cnt[j] = 0;
			int M = V[i].size();

			int l = M / 2 - 1, r = (M + 1) / 2;

			// printf("%d %d %d\n", i, l, r);

			int mx = 0;
			for(int j = V[i][l] + 1; j < V[i][r]; j++) {
				cnt[A[j]]++; mx = max(mx, cnt[A[j]]);
			}

			while(l >= 0) {
				ans = max(ans, mx + l * 2);
				if(l == 0) break;
				for(int j = V[i][l - 1] + 1; j < V[i][l]; j++) {
					cnt[A[j]]++; mx = max(mx, cnt[A[j]]);
				}
				for(int j = V[i][r] + 1; j < V[i][r + 1]; j++) {
					cnt[A[j]]++; mx = max(mx, cnt[A[j]]);
				}
				l--; r++;
			}
			// printf("%d %d\n", i, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}