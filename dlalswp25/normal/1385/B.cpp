#include <bits/stdc++.h>

using namespace std;

int A[105];
bool chk[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= 2 * N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) chk[i] = false;
		for(int i = 1; i <= 2 * N; i++) {
			if(!chk[A[i]]) printf("%d ", A[i]);
			chk[A[i]] = true;
		}
		puts("");
	}
	return 0;
}