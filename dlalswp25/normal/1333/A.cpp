#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M; scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(i == N && j == M) printf("W");
				else printf("B");
			}
			puts("");
		}
	}
	return 0;
}