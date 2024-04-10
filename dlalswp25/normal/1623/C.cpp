#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int l = 1, r = 1000000000;
		while(l <= r) {
			int m = l + r >> 1;
			bool ok = true;
			for(int i = 1; i <= N; i++) B[i] = 0;
			for(int i = N; i >= 3; i--) {
				if(A[i] + B[i] < m) { ok = false; break; }
				int t = min(A[i], A[i] + B[i] - m) / 3;
				B[i - 2] += 2 * t;
				B[i - 1] += t;
			}
			if(A[1] + B[1] < m || A[2] + B[2] < m) ok = false;
			if(ok) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", r);
	}
	return 0;
}