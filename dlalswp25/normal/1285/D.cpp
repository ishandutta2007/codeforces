#include <bits/stdc++.h>

using namespace std;

int A[101010];
int N;

int f(int b, int l, int r) {
	if(b < 0) return 0;
	int m = l;
	for(; m <= r; m++) {
		if((1 << b) & A[m]) break;
	}
	if(m == l) return f(b - 1, l, r);
	if(m > r) return f(b - 1, l, r);
	return (1 << b) + min(f(b - 1, l, m - 1), f(b - 1, m, r));
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);
	printf("%d\n", f(29, 1, N));
	return 0;
}