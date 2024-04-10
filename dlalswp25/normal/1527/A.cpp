#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int b = 1;
		while(N > 1) {
			N >>= 1;
			b <<= 1;
		}
		printf("%d\n", b - 1);
	}
	return 0;
}