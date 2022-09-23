#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		if(N > K) puts(N % K == 0 ? "1" : "2");
		else printf("%d\n", (K + N - 1) / N);
	}
	return 0;
}