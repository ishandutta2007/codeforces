#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[101010];
int B[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) { scanf("%d", &A[i]); B[i] = A[i]; }
		sort(B + 1, B + N + 1);
		bool ok = true;
		for(int i = N - X + 1; i <= X; i++) if(A[i] != B[i]) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}