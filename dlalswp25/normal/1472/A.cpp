#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int W, H, N; scanf("%d%d%d", &W, &H, &N);
		int x = 1, y = 1;
		while(W % 2 == 0) { W /= 2; x *= 2; }
		while(H % 2 == 0) { H /= 2; y *= 2; }
		puts(N <= x * y ? "YES" : "NO");
	}
	return 0;
}