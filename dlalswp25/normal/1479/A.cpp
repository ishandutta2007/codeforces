#include <bits/stdc++.h>

using namespace std;

int A[101010];

int query(int x) {
	if(A[x]) return A[x];
	printf("? %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret);
	return A[x] = ret;
}

int main() {
	int N; scanf("%d", &N);
	if(N == 1) { puts("! 1"); fflush(stdout); return 0; }
	int a = query(1), b = query(2);
	if(a < b) {
		printf("! %d\n", 1);
		fflush(stdout);
		return 0;
	}
	a = query(N - 1); b = query(N);
	if(a > b) {
		printf("! %d\n", N);
		fflush(stdout);
		return 0;
	}

	int l = 1, r = N - 1;
	while(l <= r) {
		if(l + 1 == r) {
			printf("! %d\n", r);
			fflush(stdout);
			return 0;
		}
		int m = l + r >> 1;
		a = query(m); b = query(m + 1);
		if(a < b) r = m;
		else l = m;
	}

	return 0;
}