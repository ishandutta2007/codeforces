#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int l = 0, r = 15000;
		while(l <= r) {
			int m = l + r >> 1;
			if(6 * m * m >= N) r = m - 1;
			else l = m + 1;
		}
		N -= 6 * r * r;
		if(N <= 4 * r) printf("%d\n", 3 * r + 1);
		else if(N <= 8 * r + 2) printf("%d\n", 3 * r + 2);
		else printf("%d\n", 3 * r + 3);
	}
	return 0;
}