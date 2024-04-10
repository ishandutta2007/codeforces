#include <bits/stdc++.h>

using namespace std;

int N;
int A[10101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		A[N + 1] = 1;
		int x = 1;
		for(int i = 1; i <= N + 1; i++) {
			if(A[i]) { x = i; break; }
		}
		for(int i = 1; i < x; i++) printf("%d ", i);
		printf("%d ", N + 1);
		for(int i = x; i <= N; i++) printf("%d ", i);
		puts("");
	}
	return 0;
}