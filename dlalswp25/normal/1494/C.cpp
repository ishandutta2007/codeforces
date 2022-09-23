#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[202020];
int B[202020];
int D[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= M; i++) scanf("%d", &B[i]);

		A[N + 1] = 1010101010;
		A[0] = -1010101010;

		int cutA = N + 1, cutB = M + 1;
		for(int i = 1; i <= N; i++) if(A[i] > 0) { cutA = i; break; }
		for(int i = 1; i <= M; i++) if(B[i] > 0) { cutB = i; break; }

		int ans1 = 0;
		D[N + 1] = 0;
		for(int i = N; i >= cutA; i--) {
			int t = lower_bound(B + 1, B + M + 1, A[i]) - B;
			D[i] = D[i + 1];
			if(t <= M && B[t] == A[i]) D[i]++;
		}
		ans1 = max(ans1, D[cutA]);

		int p = cutB;
		for(int i = cutA; i <= N; i++) {
			while(p <= M && B[p] < A[i]) p++;
			int x = 0;
			while(p <= M && B[p] < A[i + 1]) {
				int t = lower_bound(B + 1, B + M + 1, B[p] - (i - cutA)) - B;
				x = max(x, p - t + 1);
				p++;
			}
			ans1 = max(ans1, x + D[i + 1]);
		}

		int ans2 = 0;
		for(int i = 1; i < cutA; i++) {
			int t = lower_bound(B + 1, B + M + 1, A[i]) - B;
			D[i] = D[i - 1];
			if(t <= M && B[t] == A[i]) D[i]++;
		}
		ans2 = max(ans2, D[cutA - 1]);

		p = cutB - 1;
		for(int i = cutA - 1; i >= 1; i--) {
			while(p > 0 && B[p] > A[i]) p--;
			int x = 0;
			while(p > 0 && B[p] > A[i - 1]) {
				int t = upper_bound(B + 1, B + M + 1, B[p] + (cutA - 1 - i)) - B - 1;
				x = max(x, t - p + 1);
				p--;
			}
			ans2 = max(ans2, x + D[i - 1]);
		}
		printf("%d\n", ans1 + ans2);
	}
	return 0;
}