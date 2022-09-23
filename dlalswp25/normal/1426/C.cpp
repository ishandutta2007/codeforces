#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int l = 1, r = 40000;
		while(l <= r) {
			int m = l + r >> 1;
			if(m * m > N) r = m - 1;
			else l = m + 1;
		}

		int ans = 1010101010;
		for(int i = r - 100; i <= r + 100; i++) {
			if(i <= 0 || i > N) continue;
			ans = min(ans, i + (N - 1) / i - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}