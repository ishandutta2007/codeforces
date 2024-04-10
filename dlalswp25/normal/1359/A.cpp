#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M, K; scanf("%d%d%d", &N, &M, &K);
		if(M <= N / K) printf("%d\n", M);
		else {
			int t = M - (N / K);
			printf("%d\n", N / K - (((t - 1) / (K - 1)) + 1));
		}
	}
	return 0;
}