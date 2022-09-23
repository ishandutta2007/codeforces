#include <bits/stdc++.h>

using namespace std;

int ans[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		if(K > (N - 1) / 2) { puts("-1"); continue; }
		int x = N;
		for(int i = 1; i <= N; i++) ans[i] = 0;
		for(int i = 2; i < N; i += 2) {
			if(x <= N - K) break;
			ans[i] = x--;
		}
		x = 1;
		for(int i = 1; i <= N; i++) {
			if(ans[i]) continue;
			ans[i] = x++;
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}