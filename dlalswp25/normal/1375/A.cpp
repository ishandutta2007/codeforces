#include <bits/stdc++.h>

using namespace std;

int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(A[1] < 0) A[1] *= -1;
		for(int i = 2; i <= N; i++) {
			if(i & 1) {
				if(A[i] <= 0) A[i] *= -1;
			}
			else {
				if(A[i] >= 0) A[i] *= -1;
			}
		}

		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}