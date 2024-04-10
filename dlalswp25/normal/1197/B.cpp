#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	scanf("%d", &N);
	int x;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if(A[i] == N) x = i;
	}

	for(int i = 1; i < x; i++) {
		if(A[i] > A[i + 1]) { puts("NO"); return 0; }
	}
	for(int i = x; i < N; i++) {
		if(A[i] < A[i + 1]) { puts("NO"); return 0; }
	}
	puts("YES");
	return 0;
}