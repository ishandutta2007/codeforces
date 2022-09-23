#include <bits/stdc++.h>

using namespace std;

int N;
char A[105];

void print() {
	for(int i = 1; i <= 2 * N; i++) printf("%c", A[i]); puts("");
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			A[2 * i - 1] = '(';
			A[2 * i] = ')';
		}
		print();
		for(int i = 1; i < N; i++) {
			A[2 * i] = '(';
			A[2 * i + 1] = ')';
			print();
			A[2 * i] = ')';
			A[2 * i + 1] = '(';
		}
	}
	return 0;
}