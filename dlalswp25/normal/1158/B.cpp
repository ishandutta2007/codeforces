#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K; scanf("%d%d", &N, &K);
	if(K == 1) {
		printf("0");
		for(int i = 1; i < N; i++) printf("1"); puts("");
		return 0;
	}
	int X = (N - K) / 2 + 1;
	int c = 0;
	while(c < N) {
		if(c % X == 0) printf("0");
		else printf("1");
		c++;
	}
	puts("");
	return 0;
}