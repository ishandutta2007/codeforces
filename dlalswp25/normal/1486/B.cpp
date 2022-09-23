#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll X[1010];
ll Y[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld%lld", &X[i], &Y[i]);
		if(N & 1) { puts("1"); continue; }
		sort(X + 1, X + N + 1);
		sort(Y + 1, Y + N + 1);
		ll ans = 1;
		ans *= (X[N / 2 + 1] - X[N / 2] + 1);
		ans *= (Y[N / 2 + 1] - Y[N / 2] + 1);
		printf("%lld\n", ans);
	}
	return 0;
}