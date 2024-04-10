#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[1010101];
char B[2020202];
int D[2020202];

void f() {
	D[0] = 0; int p = 0;
	for(int i = 1; i < M; i++) {
		if(i <= p + D[p]) D[i] = min(p + D[p] - i, D[2 * p - i]);
		while(D[i] < i && i + D[i] < M - 1 && B[i + D[i] + 1] == B[i - D[i] - 1]) D[i]++;
		if(p + D[p] < i + D[i]) p = i;
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", A);
		N = strlen(A);

		for(int i = 0; i < N; i++) {
			B[2 * i] = A[i];
			B[2 * i + 1] = '#';
		}

		M = 2 * N - 1;

		int l = 0, r = M - 1;
		while(l <= r) {
			if(B[l] != B[r]) break;
			l++; r--;
		}
		if(l > r) { printf("%s\n", A); continue; }

		// printf("%s\n", B);
		// printf("%d\n", l);

		f();
		// for(int i = 0; i < M; i++) printf("%d ", D[i]); puts("");

		int lx = -1;
		for(int i = l; i <= r; i += 2) {
			int t = (l + i) / 2;
			if(D[t] >= (i - l) / 2) lx = i; 
		}
		int rx = -1;
		for(int i = r; i >= l; i -= 2) {
			int t = (r + i) / 2;
			// printf("%d %d\n", t, D[t]);
			if(D[t] >= (r - i) / 2) rx = i;
		}

		// printf("%d %d\n", lx, rx);

		if((lx - l) <= (r - rx)) {
			for(int i = 0; i < l; i += 2) printf("%c", B[i]);
			for(int i = rx; i < M; i += 2) printf("%c", B[i]);
			puts("");
		}
		else {
			for(int i = 0; i <= lx; i += 2) printf("%c", B[i]);
			for(int i = r + 2; i < M; i += 2) printf("%c", B[i]);
			puts("");
		}
		for(int i = 0; i < M; i++) D[i] = 0;
	}
	return 0;
}