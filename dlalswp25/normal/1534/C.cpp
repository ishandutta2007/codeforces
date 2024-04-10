#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N;
int A[404040];
int B[404040];
int p[404040];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 1; i <= N; i++) p[i] = i;

		for(int i = 1; i <= N; i++) unite(A[i], B[i]);
		int t = 0;
		for(int i = 1; i <= N; i++) if(p[i] == i) t++;
		int ans = 1;
		for(int i = 1; i <= t; i++) ans = ans * 2 % MOD;
		printf("%d\n", ans);
	}
	return 0;
}