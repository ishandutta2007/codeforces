#include <bits/stdc++.h>

using namespace std;

int N, K;
int H[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &H[i]);
		int lst = 0;
		for(int i = 1; i <= 10000; i++) {
			if(i > K) break;
			for(int j = 1; j <= N; j++) {
				if(j == N) { lst = -1; break; }
				if(H[j] < H[j + 1]) { H[j]++; lst = j; break; }
			}
			if(i == 10000) lst = -1;
		}
		printf("%d\n", lst);
	}
	return 0;
}