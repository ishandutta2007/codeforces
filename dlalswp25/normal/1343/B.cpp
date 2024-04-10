#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		if(N % 4) {
			puts("NO");
			continue;
		}
		puts("YES");
		long long s = 0;
		for(int i = 1; i <= N / 2; i++) {
			printf("%d ", i * 2);
			s += 2 * i;
		}
		for(int i = 1; i <= N / 2; i++) {
			if(i < N / 2) {
				printf("%d ", 2 * i - 1);
				s -= 2 * i - 1;
			}
			else printf("%lld\n", s);
		}
	}
	return 0;
}