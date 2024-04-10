#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(i == j || i + 1 == j || (i == N && j == 1)) printf("1 ");
				else printf("0 ");
			}
			puts("");
		}
	}
	return 0;
}