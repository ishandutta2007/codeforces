#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K);

		int ans = N;
		for(int i = 1; i * i <= N; i++) {
			if(N % i) continue;
			int a = i, b = N / i;
			if(a <= K) ans = min(ans, b);
			if(b <= K) ans = min(ans, a);
		}
		printf("%d\n", ans);
	}
	return 0;
}