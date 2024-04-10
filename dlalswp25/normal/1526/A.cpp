#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= 2 * N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + 2 * N + 1);
		int l = 1, r = 2 * N;
		for(int i = 1; i <= 2 * N; i++) {
			if(i & 1) printf("%d ", A[l++]);
			else printf("%d ", A[r--]);
		}
		puts("");
	}
	return 0;
}