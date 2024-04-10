#include <bits/stdc++.h>

using namespace std;

int N;
int A[7];
int B[101010];

int main() {
	for(int i = 1; i <= 6; i++) scanf("%d", &A[i]);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

	sort(A + 1, A + 7);
	sort(B + 1, B + N + 1);

	int ans = 2020202020;
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= N; j++) {
			int x = B[j] - A[i];
			if(x < B[N] - A[6]) continue;

			int mn = x;
			int l = 1;
			int k = 1;
			for(; k <= 6; k++) {
				if(l > N || B[l] - A[k] > x) continue;
				mn = min(mn, B[l] - A[k]);
				int t = upper_bound(B + l, B + N + 1, A[k] + x) - B;
				l = t;
			}
			// printf("%d %d\n", x, mn);
			ans = min(ans, x - mn);
		}
	}

	printf("%d\n", ans);
	return 0;
}