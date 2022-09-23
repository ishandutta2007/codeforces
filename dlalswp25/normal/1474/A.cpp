#include <bits/stdc++.h>

using namespace std;

char B[101010];
int A[101010];
int D[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		scanf("%s", B + 1);
		A[1] = 1; D[1] = A[1] + B[1] - '0';
		for(int i = 2; i <= N; i++) {
			if(1 + B[i] - '0' == D[i - 1]) {
				A[i] = 0; D[i] = B[i] - '0';
			}
			else {
				A[i] = 1; D[i] = B[i] - '0' + 1;
			}
		}
		for(int i = 1; i <= N; i++) printf("%d", A[i]); puts("");
	}
	return 0;
}