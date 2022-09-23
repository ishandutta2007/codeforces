#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[3][101010];

int main() {
	scanf("%d%d", &N, &Q);
	int cnt = 0;
	while(Q--) {
		int a, b; scanf("%d%d", &a, &b);
		int t;
		if(A[a][b]) t = -1;
		else t = 1;

		if(A[3 - a][b - 1]) { cnt += t; }
		if(A[3 - a][b]) cnt += t;
		if(A[3 - a][b + 1]) cnt += t;
		A[a][b] = 1 - A[a][b];
		if(cnt) puts("NO");
		else puts("YES");
	}
	return 0;
}