#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010][5];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 5; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		bool ok = false;
		for(int i = 0; i < 5; i++) {
			for(int j = i + 1; j < 5; j++) {
				int cnt[4] = {0, 0, 0, 0};
				for(int k = 1; k <= N; k++) {
					int t = A[k][i] << 1 | A[k][j];
					cnt[t]++;
				}
				if(cnt[0]) continue;
				if(cnt[1] > N / 2 || cnt[2] > N / 2) continue;
				ok = true;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}