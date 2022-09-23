#include <bits/stdc++.h>

using namespace std;

int A[202020];
int B[202020];
int cnt[202020];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		A[x] = i;
	}
	for(int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
		B[i] = A[B[i]];
		cnt[(N + (B[i] - i)) % N]++;
	}

	int ans = 0;
	for(int i = 0; i < N; i++) ans = max(ans, cnt[i]);
	printf("%d\n", ans);

	return 0;
}