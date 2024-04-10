#include <bits/stdc++.h>

using namespace std;

int A[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		int l = 1, r = N;
		int x = -1;
		for(int i = N; i >= 1; i--) {
			if(A[l] == i) { l++; continue; }
			if(A[r] == i) { r--; continue; }
			x = i; break;
		}

		if(x == -1) { puts("NO"); continue; }

		int y;
		for(int i = l; i <= r; i++) {
			if(A[i] == x) { y = i; break; }
		}

		puts("YES");
		printf("%d %d %d\n", l, y, r);
	}
	return 0;
}