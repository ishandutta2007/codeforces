#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M; scanf("%d%d", &N, &M);
	if(N == M) { puts("0"); return 0; }
	if(M == 0) { puts("1"); return 0; }
	if(M * 2 <= N) { printf("%d\n", M); return 0; }
	printf("%d\n", N - M);
	return 0;
}