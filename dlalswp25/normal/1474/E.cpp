#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		ll ans = 0;
		int M = (N + 1) / 2;
		for(int i = M + 1; i <= N; i++) ans += (ll)(i - 1) * (i - 1);
		for(int i = M; i > 1; i--) ans += (ll)(N - i) * (N - i);
		printf("%lld\n", ans);
		if(N == 2) {
			printf("2 1\n1\n2 1\n");
		}
		else {
			printf("%d %d ", M + 1, 1);
			for(int i = 3; i <= M; i++) printf("%d ", i - 1);
			for(int i = M + 1; i < N; i++) printf("%d ", i + 1);
			printf("%d\n", M);

			printf("%d\n", N - 1);
			for(int i = M + 1; i < N; i++) printf("%d %d\n", i, 1);
			for(int i = M; i >= 2; i--) printf("%d %d\n", i, N);
			printf("%d %d\n", 1, N);
		}
	}
	return 0;
}