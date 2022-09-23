#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		puts("2");
		printf("%d %d\n", N - 1, N);
		for(int i = N - 1; i > 1; i--) {
			printf("%d %d\n", i - 1, i + 1);
		}
	}
	return 0;
}