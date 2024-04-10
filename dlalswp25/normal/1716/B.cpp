#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		printf("%d\n", N);
		for(int i = 1; i <= N; i++) {
			for(int j = 2; j <= i; j++) printf("%d ", j);
			printf("1 ");
			for(int j = i + 1; j <= N; j++) printf("%d ", j);
			puts("");
		}	
	}
	return 0;
}