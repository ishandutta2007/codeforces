#include <bits/stdc++.h>

using namespace std;

int N, S;
int A[1010101];

int main() {
	scanf("%d%d", &N, &S);
	if(N * 2 > S) { puts("NO"); return 0; }
	puts("YES");
	for(int i = 1; i < N; i++) {
		printf("2 ");
	}
	printf("%d\n1\n", S - 2 * (N - 1));
	return 0;
}