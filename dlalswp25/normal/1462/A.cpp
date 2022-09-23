#include <bits/stdc++.h>

using namespace std;

int N;
int A[305];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int l = 1, r = N;
		for(int i = 1; i <= N; i++) {
			if(i & 1) { printf("%d ", A[l]); l++; }
			else { printf("%d ", A[r]); r--; }
		}
		puts("");
	}
	return 0;
}