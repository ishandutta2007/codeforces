#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		if(N & 1) {
			if(K == 1) {
				puts("YES");
				for(int i = 1; i <= N; i++) printf("%d\n", i);
			}
			else puts("NO");
			continue;
		}
		puts("YES");
		int x = 1;
		for(int i = 1; i <= N / 2; i++) {
			for(int j = 1; j <= K; j++) { printf("%d ", x); x += 2; }
			puts("");
		}
		x = 2;
		for(int i = 1; i <= N / 2; i++) {
			for(int j = 1; j <= K; j++) { printf("%d ", x); x += 2; }
			puts("");
		}
	}
	return 0;
}