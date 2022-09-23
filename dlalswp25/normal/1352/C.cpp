#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K); K--;
		int x = K / (N - 1);
		printf("%d\n", x * N + (K % (N - 1)) + 1);
	}
	return 0;
}