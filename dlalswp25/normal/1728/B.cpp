#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N & 1) {
			for(int i = N - 2; i > 3; i--) printf("%d ", i);
			printf("1 2 3 ");
		}
		else {
			for(int i = N - 2; i >= 1; i--) printf("%d ", i);
		}
		printf("%d %d\n", N - 1, N);
	}
	return 0;
}