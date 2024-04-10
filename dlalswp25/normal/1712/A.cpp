#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			if(i <= K && a <= K) ans++;
		}
		printf("%d\n", K - ans);
	}
	return 0;
}