#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		int x = 0;
		for(int i = 0; i < N; i++) {
			int b = x ^ i;
			printf("%d\n", b); fflush(stdout);
			int r; scanf("%d", &r);
			if(r == -1) return 0;
			if(r) break;
			else x ^= b;
		}
	}
	return 0;
}