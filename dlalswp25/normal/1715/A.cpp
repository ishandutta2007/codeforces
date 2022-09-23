#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		if(N == 1 && M == 1) puts("0");
		else printf("%d\n", N - 1 + M - 1 + 1 + min(N, M) - 1);
	}
	return 0;
}