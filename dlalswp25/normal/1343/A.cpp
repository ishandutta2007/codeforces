#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int k = 2; k <= 30; k++) {
			if(N % ((1 << k) - 1) == 0) {
				printf("%d\n", N / ((1 << k) - 1));
				break;
			}
		}
	}
	return 0;
}