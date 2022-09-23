#include <bits/stdc++.h>

using namespace std;

int N;
int A[303030];
int B[303030];

int f(int a, int b, int c) {
	if(b > a && b > c) return 1;
	if(b < a && b < c) return -1;
	return 0;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		B[1] = B[N] = 0;
		for(int i = 2; i < N; i++) {
			B[i] = f(A[i - 1], A[i], A[i + 1]);
		}

		int tot = 0;
		for(int i = 2; i < N; i++) tot += abs(B[i]);
		int ans = tot;

		for(int i = 2; i < N; i++) {
			int t = 0;
			t = abs(B[i]) + abs(B[i - 1]);
			if(i < N - 1) t -= abs(f(A[i - 1], A[i + 1], A[i + 2])) - abs(B[i + 1]);
			ans = min(ans, tot - t);
			t = abs(B[i]) + abs(B[i + 1]);
			if(i > 2) t -= abs(f(A[i - 2], A[i - 1], A[i + 1])) - abs(B[i - 1]);
			ans = min(ans, tot - t);
		}
		printf("%d\n", ans);
	}
	return 0;
}