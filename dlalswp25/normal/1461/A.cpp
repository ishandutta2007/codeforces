#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) {
			printf("%c", 'a' + i % 3);
		}
		puts("");
	}
	return 0;
}