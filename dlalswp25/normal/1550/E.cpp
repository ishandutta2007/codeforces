#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[202020];
int B[202020];
int D[202020];
int nxt[20][202020];
queue<int> q;

bool solve(int x) {
	for(int i = 1; i <= N; i++) B[i] = 0;
	for(int i = 0; i < K; i++) {
		int r = N + 1;
		for(int j = N; j >= 1; j--) {
			if(A[j] != i + 'a' && A[j] != '?') r = j;
			if(r - j >= x) B[j] |= (1 << i);
		}
	}

	for(int i = 0; i < K; i++) nxt[i][N + 1] = nxt[i][N + 2] = N + 2;
	for(int i = 0; i < K; i++) {
		int r = N + 2;
		for(int j = N; j >= 1; j--) {
			if(B[j] & 1 << i) r = j + x;
			nxt[i][j] = r;
		}
	}

	q.push(0);
	D[0] = 1;
	for(int i = 1; i < 1 << K; i++) D[i] = 1010101010;

	while(q.size()) {
		int now = q.front(); q.pop();
		for(int i = 0; i < K; i++) {
			if(now & 1 << i) continue;
			int t = now | 1 << i;
			if(D[t] == 1010101010) q.push(t);
			D[t] = min(D[t], nxt[i][D[now]]);
		}
	}
	return D[(1 << K) - 1] <= N + 1;
}

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", A + 1);

	int l = 0, r = N;
	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r);

	return 0;
}