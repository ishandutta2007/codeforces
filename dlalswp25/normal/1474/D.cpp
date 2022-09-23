#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int L[202020];
int R[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		L[1] = A[1];
		for(int i = 2; i <= N; i++) {
			if(L[i - 1] == -1 || L[i - 1] > A[i]) L[i] = -1;
			else L[i] = A[i] - L[i - 1];
		}
		R[N] = A[N];
		for(int i = N - 1; i >= 1; i--) {
			if(R[i + 1] == -1 || R[i + 1] > A[i]) R[i] = -1;
			else R[i] = A[i] - R[i + 1];
		}

		if(L[N] == 0) { puts("YES"); continue; }
		if(N == 2) { puts("NO"); continue; }
		if(R[3] != -1 && A[1] >= R[3] && A[2] == (A[1] - R[3])) { puts("YES"); continue; }
		if(L[N - 2] != -1 && A[N] >= L[N - 2] && A[N - 1] == (A[N] - L[N - 2])) { puts("YES"); continue; }
		bool ok = false;
		for(int i = 2; i <= N - 2; i++) {
			if(L[i - 1] == -1 || R[i + 2] == -1) continue;
			if(L[i - 1] > A[i + 1] || R[i + 2] > A[i]) continue;
			if(A[i] + L[i - 1] == A[i + 1] + R[i + 2]) { ok = true; break; }
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}