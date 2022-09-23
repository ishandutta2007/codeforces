#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		int t = N - (2 * (N - K) + 1);
		for(int i = 1; i <= t; i++) printf("%d ", i);
		for(int i = K; i > t; i--) printf("%d ", i); puts("");
	}
	return 0;
}