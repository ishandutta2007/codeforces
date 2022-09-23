#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int A[303030];
ll D[303030][2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
		}
		for(int i = 1; i <= N; i++) {
			D[i][0] = max(D[i - 1][0], D[i - 1][1] + A[i]);
			D[i][1] = max(D[i - 1][1], D[i - 1][0] - A[i]);
			D[i][1] = max(0LL, D[i][1]);
		}
		printf("%lld\n", max(D[N][0], D[N][1]));
	}
	return 0;
}