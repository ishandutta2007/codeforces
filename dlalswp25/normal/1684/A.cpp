#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N <= 99) printf("%d\n", N % 10);
		else {
			int ans = 9;
			while(N) {
				ans = min(ans, N % 10);
				N /= 10;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}