#include <bits/stdc++.h>

using namespace std;

int N, M;
int C[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < M; i++) C[i] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			C[a % M]++;
		}

		int ans = (C[0] > 0);
		for(int i = 1; i < M; i++) {
			if(i > M - i) break;
			if(i == M - i) {
				ans += (C[i] > 0);
			}
			else {
				int a = C[i], b = C[M - i];
				if(a > b) swap(a, b);
				if(!b) continue;

				ans += max(1, b - a);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}