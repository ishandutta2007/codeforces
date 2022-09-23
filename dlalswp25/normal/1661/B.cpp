#include <bits/stdc++.h>

using namespace std;

const int MX = 32768;

int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		if(!a) { puts("0"); continue; }
		int ans = 15;
		for(int j = 0; j < 15; j++) {
			int t = 1 << j + 1;
			int c = (t - a % t) % t;
			ans = min(ans, c + 14 - j);
		}
		printf("%d ", ans);
	}
	puts("");
	return 0;
}