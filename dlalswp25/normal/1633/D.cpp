#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int N, K;
int D[1010];
int B[1010];
int C[1010];
int dp[15151];

int main() {
	for(int i = 1; i <= MX; i++) D[i] = -1;
	D[1] = 0;
	queue<int> q; q.push(1);
	while(q.size()) {
		int x = q.front(); q.pop();
		for(int i = 1; i <= x; i++) {
			int t = x + x / i;
			if(t > MX) continue;
			if(D[t] == -1) {
				D[t] = D[x] + 1;
				q.push(t);
			}
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
		for(int i = 1; i <= N; i++) B[i] = D[B[i]];
		int s = 0;
		for(int i = 1; i <= N; i++) s += B[i];
		if(s <= K) {
			int ans = 0;
			for(int i = 1; i <= N; i++) ans += C[i];
			printf("%d\n", ans);
			continue;
		}

		for(int i = 1; i <= K; i++) dp[i] = -1010101010;
		dp[0] = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = K; j >= B[i]; j--) {
				dp[j] = max(dp[j], dp[j - B[i]] + C[i]);
			}
		}
		int ans = 0;
		for(int i = 0; i <= K; i++) ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}