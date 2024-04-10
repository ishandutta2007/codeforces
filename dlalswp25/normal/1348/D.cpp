#include <bits/stdc++.h>

using namespace std;

int A[35];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		int tmp = N;
		int ans = 0;
		while(tmp) { ans++; tmp >>= 1; }
		printf("%d\n", ans - 1);

		for(int i = 1; i <= ans; i++) A[i] = 1 << i - 1;
		
		int x = (1 << ans) - 1 - N;

		for(int i = 1; i <= ans; i++) {
			int dx = (1 << (ans - i + 1)) - 1;
			while(x >= dx) {
				x -= dx;
				for(int j = i; j <= ans; j++) {
					A[j] -= (1 << j - i);
				}
			}
		}

		for(int i = 2; i <= ans; i++) printf("%d ", A[i] - A[i - 1]); puts("");
	}
	return 0;
}