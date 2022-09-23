#include <bits/stdc++.h>

using namespace std;

void put(int x) {
	printf("%d ", x);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		if(N < 4) { puts("-1"); continue; }
		if(N == 4) { printf("3 1 4 2\n"); continue; }
		int x = 1;
		while(x <= N - 2) {
			put(x);
			x += 2;
		}
		put(x);
		if(N & 1) {
			x -= 3; put(x);
			x += 2; put(x);
			x -= 4;
			while(x > 0) {
				put(x); x -= 2;
			}
		}
		else {
			x -= 3; put(x);
			x += 4; put(x);
			x -= 2; put(x);
			x -= 4;
			while(x > 0) { put(x); x -= 2; }
		}
		puts("");
	}
	return 0;
}