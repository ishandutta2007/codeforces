#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int X = 100500;

int L[303030];
int R[303030];
int A[101010];
int N, M;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) scanf("%d", &A[i]);

	if(N == 1) { puts("0"); return 0; }

	for(int i = M; i >= 1; i--) {
		L[i + A[i] + X] = L[i + A[i] + 1 + X] + 1;
		R[i - A[i] + X] = R[i - A[i] + 1 + X] + 1;
	}

	ll ans = 0;

	for(int i = 1; i <= N; i++) {
		int l = max(1, i - (M + 1) + L[i + X]);
		int r = min(N, i + (M + 1) - R[-i + X]);
		ans += (r - l + 1);
		//printf("%d %d %d\n", i, l, r);
	}
	printf("%lld\n", ans);

	return 0;
}