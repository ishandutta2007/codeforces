#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 61;

int N;
ll K;
ll D[200];
int ans[101010];

int main() {
	D[0] = D[1] = 1;
	for(int i = 2; i <= 200; i++) {
		for(int j = 1; j <= i; j++) {
			D[i] = (D[i] + D[i - j]);
			if(D[i] > INF) D[i] = INF;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &K);
		if(N <= 200 && D[N] < K) { puts("-1"); continue; }
		K--;
		for(int i = 1; i <= N; i++) {
			if(i <= N - 200) { ans[i] = i; continue; }
			int x = N - i + 1;
			for(int j = i; ; j++) {
				if(D[x - (j - i + 1)] <= K) {
					K -= D[x - (j - i + 1)];
				}
				else {
					for(int k = i; k <= j; k++) {
						ans[k] = j - (k - i);
					}
					i = j;
					break;
				}
			}
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}