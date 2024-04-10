#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		if(N == 1) {
			printf("%c%c\n", A[1], A[1]);
			continue;
		}
		if(A[1] <= A[2]) {
			printf("%c%c\n", A[1], A[1]);
			continue;
		}

		int t = N;
		for(int i = 1; i < N; i++) {
			if(A[i] < A[i + 1]) {
				t = i; break;
			}
		}
		for(int i = 1; i <= t; i++) printf("%c", A[i]);
		for(int i = t; i >= 1; i--) printf("%c", A[i]);
		puts("");
	}
	return 0;
}