#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int S[202020];
int need[262626];

int main() {
	need[0] = 1; need[1] = 0;
	for(int i = 0; i < 18; i++) {
		for(int j = (1 << i) + 1; j <= 1 << i + 1; j++) {
			need[j] = (1 << i + 1) - j;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) A[i] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			A[a]++;
		}
		for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
		int ans = 1010101010;
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= 18; j++) {
				int l = i + 1, r = N;
				while(l <= r) {
					int m = l + r >> 1;
					if(S[m] - S[i] > 1 << j) r = m - 1;
					else l = m + 1;
				}
				ans = min(ans, need[S[i]] + need[S[r] - S[i]] + need[N - S[r]]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}