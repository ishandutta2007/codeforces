#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		if(K > (N + 1) / 2) { puts("-1"); continue; }
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(i == j && i % 2 == 1 && i <= 2 * K - 1) printf("R");
				else printf(".");
			}
			puts("");
		}
	}
	return 0;
}