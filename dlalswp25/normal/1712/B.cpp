#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N & 1) {
			printf("1 ");
			for(int i = 2; i <= N; i += 2) printf("%d %d ", i + 1, i);
		}
		else {
			for(int i = 1; i <= N; i += 2) printf("%d %d ", i + 1, i);
		}
		puts("");
	}
	return 0;
}