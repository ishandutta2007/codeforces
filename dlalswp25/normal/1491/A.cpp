#include <bits/stdc++.h>

using namespace std;

int A[101010];

int main() {
	int N, Q; scanf("%d%d", &N, &Q);
	int a = 0, b = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if(A[i]) b++;
		else a++;
	}

	while(Q--) {
		int t, x; scanf("%d%d", &t, &x);
		if(t == 1) {
			if(A[x]) {
				b--; a++;
			}
			else {
				b++; a--;
			}
			A[x] = 1 - A[x];
		}
		else {
			if(b < x) puts("0");
			else puts("1");
		}
	}

	return 0;
}