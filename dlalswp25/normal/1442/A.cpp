#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[30303];
ll B[30303];
ll C[30303];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i < N; i++) {
			if(A[i] > A[i + 1]) B[i] = A[i] - A[i + 1];
			else B[i] = 0;
		}
		for(int i = 2; i <= N; i++) {
			if(A[i] > A[i - 1]) C[i] = A[i] - A[i - 1];
			else C[i] = 0;
		}
		B[N] = B[N + 1] = 0; C[1] = 0;
		for(int i = N; i >= 1; i--) B[i] += B[i + 1];
		for(int i = 1; i <= N; i++) C[i] += C[i - 1];
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i] < B[i] + C[i]) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}