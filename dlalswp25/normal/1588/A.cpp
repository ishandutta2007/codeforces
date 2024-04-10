#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];
int B[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		sort(A + 1, A + N + 1);
		sort(B + 1, B + N + 1);
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(B[i] < A[i] || B[i] > A[i] + 1) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}