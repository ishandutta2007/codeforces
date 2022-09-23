#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[1010101];
char ans[1010101];
int lft[1010101];
int B;

int T[2121212];
int base;

void upd(int p) {
	// printf("upd %d\n", p);
	p += base;
	if(T[p]) return;
	T[p]++;
	while(p > 1) {
		p >>= 1;
		T[p] = T[p << 1] + T[p << 1 | 1];
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		int tmp = 1; B = 0;
		while(tmp <= N - K + 1) {
			tmp <<= 1; B++;
		}
		B = min(B, K);

		scanf("%s", A + 1);
		for(int i = 1; i <= K - B; i++) ans[i] = '0';
		ans[K + 1] = 0;

		for(int i = 1; i <= N; i++) {
			lft[i] = lft[i - 1];
			if(A[i] == '1') lft[i]++;
			else lft[i] = 0;
		}

		base = (1 << B);
		for(int i = 0; i < 2 * base; i++) T[i] = 0;

		for(int i = 0; i <= N - B; i++) {
			if(lft[i] < K - B) continue;
			int v = 0;
			for(int j = 1; j <= B; j++) {
				v <<= 1;
				if(A[i + j] == '0') v |= 1;
			}
			upd(v);
		}

		int now = 1;
		int sz = (1 << B);
		if(T[now] == sz) { puts("NO"); continue; }

		for(int i = 1; i <= B; i++) {
			if(T[now << 1] == sz / 2) {
				ans[K - B + i] = '1';
				now = now << 1 | 1;
			}
			else {
				ans[K - B + i] = '0';
				now = now << 1;
			}
			sz >>= 1;
		}

		puts("YES");
		printf("%s\n", ans + 1);
	}
	return 0;
}