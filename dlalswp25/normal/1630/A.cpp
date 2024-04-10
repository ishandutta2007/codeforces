#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans[65656];

void f(int a, int b) {
	ans[a] = b; ans[b] = a;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		if(N == 4 && K == 3) { puts("-1"); continue; }
		for(int i = 0; i < N; i++) ans[i] = N - i - 1;
		if(K == N - 1) {
			f(N - 1, N - 2);
			f(0, 1);
			f(N / 2 - 2, N / 2);
			f(N / 2 - 1, N / 2 + 1);
		}
		else if(K) {
			f(K, N - 1);
			f(0, N - K - 1);
		}
		for(int i = 0; i < N; i++) {
			if(i < ans[i]) printf("%d %d\n", i, ans[i]);
		}
	}
	return 0;
}