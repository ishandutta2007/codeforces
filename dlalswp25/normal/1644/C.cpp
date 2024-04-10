#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, X;
int A[5050];
int mx[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		mx[0] = 0;
		for(int i = 1; i <= N; i++) mx[i] = -INF;
		for(int i = 1; i <= N; i++) {
			int s = 0;
			for(int j = i; j <= N; j++) {
				s += A[j];
				mx[j - i + 1] = max(mx[j - i + 1], s);
			}
		}

		for(int i = 0; i <= N; i++) {
			int ans = -INF;
			for(int j = 0; j <= N; j++) {
				ans = max(ans, mx[j] + X * min(i, j));
			}
			printf("%d ", ans);
		}
		puts("");
	}
	return 0;
}