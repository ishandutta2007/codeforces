#include <bits/stdc++.h>

using namespace std;

int N;
char C;
char A[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d %c", &N, &C);
		scanf("%s", A + 1);
		int x = 0;
		for(int i = 1; i <= N; i++) {
			bool ok = true;
			for(int j = i; j <= N; j += i) {
				if(A[j] != C) ok = false;
			}
			if(ok) { x = i; break; }
		}
		if(x == 1) {
			puts("0"); continue;
		}
		else if(x) {
			printf("1\n%d\n", x);
		}
		else {
			printf("2\n%d %d\n", N - 1, N);
		}
	}
	return 0;
}