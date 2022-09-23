#include <bits/stdc++.h>

using namespace std;

int N;
int A[505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int x = N + 1;
		for(int i = 1; i <= N; i++) {
			if(A[i] != i) { x = i; break; }
		}
		if(x <= N) {
			for(int i = x; i <= N; i++) {
				if(A[i] == x) {
					reverse(A + x, A + i + 1);
					break;
				}
			}
		}
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}