#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int mx = 0;
		while(N) {
			mx = max(mx, N % 10);
			N /= 10;
		}
		printf("%d\n", mx);
	}
	return 0;
}