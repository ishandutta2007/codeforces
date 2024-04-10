#include <bits/stdc++.h>

using namespace std;

int A[10101];
set<int> S;

int query(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int t; scanf("%d", &t);
	return t;
}

int main() {
	int N; scanf("%d", &N);

	if(N == 1) {
		puts("! 1");
		fflush(stdout);
		return 0;
	}

	for(int i = 1; i <= N; i++) S.insert(i);
	for(int i = 1; i < N; i++) {
		int a = *S.begin(); S.erase(S.begin());
		int b = *S.begin(); S.erase(S.begin());
		int qa = query(a, b);
		int qb = query(b, a);
		if(qa > qb) {
			A[a] = qa;
			S.insert(b);
		}
		else {
			A[b] = qb;
			S.insert(a);
		}
	}
	A[*S.begin()] = N;
	printf("! ");
	for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	fflush(stdout);
	return 0;
}