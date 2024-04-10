#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[505][505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N + N; i++) {
			for(int j = 1; j <= N + N; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		ll ans = 0;
		for(int i = N + 1; i <= N + N; i++) {
			for(int j = N + 1; j <= N + N; j++) ans += A[i][j];
		}
		ans += min({A[N + 1][1], A[N + 1][N], A[N + N][1], A[N + N][N], A[1][N + 1], A[1][N + N], A[N][N + 1], A[N][N + N]});
		printf("%lld\n", ans);
	}
	return 0;
}