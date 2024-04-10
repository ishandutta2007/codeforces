#include <bits/stdc++.h>

using namespace std;

int ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		for(int i = 1; i <= K; i++) ans[i] = 0;

		if(N - K <= K) {
			for(int i = 1; i <= K; i++) ans[i]++;
			for(int i = 1; i <= N - K; i++) ans[i]++;
		}
		else {
			int X = K;
			int M = N;

			if(K % 2 == 0) { X--; M--; ans[K] = 1; }

			int t = 0;
			while((~M & 1) && M - X > X) { M >>= 1; t++; }

			if(M - X <= X) {
				for(int i = 1; i <= X; i++) ans[i] += 1 << t;
				for(int i = 1; i <= M - X; i++) ans[i] += 1 << t;
			}
			else {
				for(int i = 1; i <= X; i++) ans[i] = 1;
				ans[1] += (M - X) / 2;
				ans[2] += (M - X) / 2;
				for(int i = 1; i <= X; i++) ans[i] <<= t;
			}
		}

		for(int i = 1; i <= K; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}