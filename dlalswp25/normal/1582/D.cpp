#include <bits/stdc++.h>

using namespace std;

const int MX = 10000;

int N;
int A[101010];
int B[101010];
int bef[20202];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) B[i] = 0;

		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		if(N & 1) {
			if(A[1] + A[2]) {
				B[3] = -A[1] - A[2];
				B[1] = B[2] = A[3];
			}
			else if(A[2] + A[3]) {
				B[1] = -A[2] - A[3];
				B[2] = B[3] = A[1];
			}
			else {
				B[2] = -A[3] - A[1];
				B[3] = B[1] = A[2];
			}
		}

		for(int i = 1; i <= N; i++) {
			if(B[i]) continue;
			if(bef[A[i] + MX]) {
				B[bef[A[i] + MX]] = 1;
				B[i] = -1;
				bef[A[i] + MX] = 0;
				continue;
			}
			else {
				bef[A[i] + MX] = i;
			}
		}

		int lst = -1;
		for(int i = N; i >= 1; i--) {
			if(!B[i]) { lst = i; break; }
		}
		if(lst != -1) {
			for(int i = 1; i <= N; i++) {
				if(i == lst || B[i]) continue;
				if(A[i] > 0) { B[lst] -= A[i]; B[i] = A[lst]; }
				else { B[lst] += A[i]; B[i] = -A[lst]; }
			}
		}
		for(int i = 1; i <= N; i++) printf("%d " , B[i]); puts("");

		for(int i = 1; i <= N; i++) bef[A[i] + MX] = 0;
	}
	return 0;
}