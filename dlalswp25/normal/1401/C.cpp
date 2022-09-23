#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int B[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int mn = 1010101010;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			mn = min(mn, A[i]);
			B[i] = A[i];
		}
		sort(B + 1, B + N + 1);

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(B[i] != A[i] && A[i] % mn) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}