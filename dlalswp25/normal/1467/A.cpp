#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N == 1) puts("9");
		else {
			printf("98");
			int t = 9;
			for(int i = 3; i <= N; i++) {
				printf("%d", t);
				t = (t + 1) % 10;
			}
			puts("");
		}
	}
	return 0;
}