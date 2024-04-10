#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);

		int b = 1;
		for(int i = 2; i * i <= N; i++) {
			if(N % i == 0) {
				b = N / i; break;
			}
		}
		printf("%d %d\n", b, N - b);
	}
	return 0;
}