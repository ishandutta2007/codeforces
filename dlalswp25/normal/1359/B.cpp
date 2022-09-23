#include <bits/stdc++.h>

using namespace std;

char A[105][1010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M, X, Y; scanf("%d%d%d%d", &N, &M, &X, &Y);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			int p = 1;
			while(p <= M) {
				if(A[i][p] == '*') { p++; continue; }
				int c = 0;
				while(p <= M && A[i][p] == '.') {
					c++; p++;
				}
				if(X * 2 <= Y) ans += c * X;
				else ans += (c / 2) * Y + (c % 2) * X;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}