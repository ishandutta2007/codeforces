#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pw[15];
int N, K;
int A[15];
int mx[15];

ll f(int n, int k) {
	if(n == 1) return k;
	if(mx[n - 1] >= k) return f(n - 1, k);
	int t = (k - mx[n - 1]);
	return pw[A[n]] * t + f(n - 1, k - t);
}

int main() {
	pw[0] = 1;
	for(int i = 1; i <= 9; i++) pw[i] = pw[i - 1] * 10;
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i < N; i++) {
			mx[i] = mx[i - 1] + pw[A[i + 1] - A[i]] - 1;
		}
		printf("%lld\n", f(N, K + 1));
	}
	return 0;
}