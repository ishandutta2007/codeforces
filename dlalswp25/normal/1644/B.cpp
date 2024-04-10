#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N == 3) {
			printf("3 2 1\n1 3 2\n3 1 2\n");
		}
		else {
			for(int i = N; i >= 1; i--) {
				int x = i;
				for(int j = 0; j < N; j++) {
					printf("%d ", x); x--;
					if(!x) x = N;
				}
				puts("");
			}
		}
	}
	return 0;
}