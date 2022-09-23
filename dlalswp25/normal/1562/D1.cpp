#include <bits/stdc++.h>

using namespace std;

int N, Q;
char A[303030];
int S[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		scanf("%s", A + 1);
		for(int i = 1; i <= N; i++) {
			int t = (A[i] == '+' ? 1 : -1);
			if(~i & 1) t *= -1;
			S[i] = S[i - 1] + t;
		}
		while(Q--) {
			int l, r; scanf("%d%d", &l, &r);
			if(S[r] - S[l - 1] == 0) { puts("0"); continue; }
			if((r - l) & 1) puts("2");
			else puts("1");
		}
	}
	return 0;
}