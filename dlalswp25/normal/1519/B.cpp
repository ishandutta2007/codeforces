#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M, K; scanf("%d%d%d", &N, &M, &K);
		puts(M - 1 + M * (N - 1) == K ? "YES" : "NO");
	}
	return 0;
}