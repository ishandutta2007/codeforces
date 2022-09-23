#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans[1010][1010];
int C = 0;

void solve(int l, int r, int c) {
	C = max(C, c);
	int n = r - l + 1;
	if(n <= K) {
		for(int i = l; i <= r; i++) {
			for(int j = i + 1; j <= r; j++) {
				ans[i][j] = c;
			}
		}
		return;
	}
	int x = n / K;
	int y = n % K;
	int p = l;
	for(int i = 0; i < y; i++) {
		solve(p, p + x, c + 1);
		p += x + 1;
	}
	for(int i = 0; i < K - y; i++) {
		solve(p, p + x - 1, c + 1);
		p += x;
	}

	for(int i = l; i <= r; i++) {
		for(int j = l + 1; j <= r; j++) {
			if(!ans[i][j]) ans[i][j] = c;
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	solve(1, N, 1);
	printf("%d\n", C);
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) printf("%d ", ans[i][j]);
	}
	puts("");
	return 0;
}