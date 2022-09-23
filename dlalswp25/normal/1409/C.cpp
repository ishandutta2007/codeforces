#include <bits/stdc++.h>

using namespace std;

int N, x, y;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &x, &y);
		int d = y - x;

		int g;
		for(int i = 1; i <= d; i++) {
			if(d % i) continue;
			if(d / i + 1 > N) continue;
			g = i; break;
		}

		int tmp = y;
		int c = 0;
		while(tmp > 0) {
			printf("%d ", tmp);
			tmp -= g;
			c++;
			if(c >= N) break;
		}

		for(; c < N; c++) { y += g; printf("%d ", y); }
		puts("");
	}
	return 0;
}