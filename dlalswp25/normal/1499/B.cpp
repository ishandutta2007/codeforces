#include <bits/stdc++.h>

using namespace std;

int N;
char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int L, R;
		for(L = 2; L <= N; L++) {
			if(A[L] == '1' && A[L - 1] == '1') {
				L--; break;
			}
		}

		for(R = N - 1; R >= 1; R--) {
			if(A[R] == '0' && A[R + 1] == '0') {
				break;
			}
		}

		if(L < R) puts("NO");
		else puts("YES");
	}
	return 0;
}