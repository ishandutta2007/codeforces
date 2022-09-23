#include <bits/stdc++.h>

using namespace std;

int N;
int A[101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(N == 1) { puts("0"); continue; }
		int ans = N;
		for(int i = 1; i <= N; i++) {
			for(int j = i + 1; j <= N; j++) {
				int cnt = 0;
				for(int k = 1; k <= N; k++) {
					if(k == i || k == j) continue;
					if((A[i] - A[k]) * (j - k) == (A[j] - A[k]) * (i - k)) continue;
					cnt++;
				}
				ans = min(ans, cnt);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}