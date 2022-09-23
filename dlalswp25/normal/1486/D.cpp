#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[202020];
int D[202020];

bool solve(int x) {
	int s = 0;
	int mn = 10101010;
	D[0] = 0;
	for(int i = 1; i <= N; i++) {
		if(A[i] >= x) s++;
		else s--;
		D[i] = s;
		if(i >= K) mn = min(mn, D[i - K]);
		if(s > mn) return true;
		D[i] = s;
	}
	return false;
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	int l = 1, r = N;
	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r);
	return 0;
}