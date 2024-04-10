#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int d = 0, tmp = N;
		while(tmp) { tmp /= 10; d++; }
		printf("%d\n", 10 * (N % 10 - 1) + d * (d + 1) / 2);
	}
	return 0;
}