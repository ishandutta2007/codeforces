#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, k1, k2, W, B;
		scanf("%d%d%d%d%d", &N, &k1, &k2, &W, &B);
		if(k1 + k2 < W * 2 || (2 * N - k1 - k2) < B * 2) puts("NO");
		else puts("YES");
	}
	return 0;
}