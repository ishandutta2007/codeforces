#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];
int B[105];

int mx[105][10101];

int main() {
	scanf("%d", &N);
	int tot = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i], &B[i]);
		tot += B[i];
	}
	for(int k = 0; k <= 100; k++) for(int i = 0; i <= 10000; i++) mx[k][i] = -10101010;
	mx[0][0] = 0;
	for(int i = 1; i <= N; i++) {
		for(int k = N; k >= 1; k--) {
			for(int j = N * 100; j >= A[i]; j--) {
				mx[k][j] = max(mx[k][j], mx[k - 1][j - A[i]] + B[i]);
			}
		}
	}

	for(int k = 1; k <= N; k++) {
		int ans = 0;
		for(int i = 1; i <= N * 100; i++) {
			ans = max(ans, min(2 * i, tot + mx[k][i]));
		}
		printf("%d.%d ", ans / 2, ans % 2 * 5);
	}
	puts("");

	return 0;
}