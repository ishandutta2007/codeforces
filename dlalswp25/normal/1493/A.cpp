#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		printf("%d\n", N - K + K / 2);
		for(int i = (K + 1) / 2; i < K; i++) printf("%d ", i);
		for(int i = K + 1; i <= N; i++) printf("%d ", i);
		puts("");
	}
	return 0;
}