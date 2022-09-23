#include <bits/stdc++.h>

using namespace std;

int A[303030][10];
int cnt[515];
int N, M;
int x1, x2;

bool solve(int m) {
	for(int i = 1; i <= N; i++) {
		int b = 0;
		for(int j = 1; j <= M; j++) {
			if(A[i][j] >= m) b += (1 << (j - 1));
		}
		cnt[b] = i;
	}

	bool ok = false;

	for(int i = 0; i < (1 << M); i++) {
		if(!cnt[i]) continue;
		int all = ((1 << M) - 1) ^ i;
		for(int j = 0; j < (1 << M); j++) {
			if((all & j) == all) {
				if(cnt[j]) {
					ok = true;
					x1 = cnt[i]; x2 = cnt[j];
				}
			}
		}
	}
	if(ok) return true;
	else return false;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);

	int l = 0, r = 1000000000;
	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) l = m + 1;
		else r = m - 1;
		for(int i = 0; i < (1 << M); i++) cnt[i] = 0;
	}

	solve(r);
	printf("%d %d\n", x1, x2);

	return 0;
}