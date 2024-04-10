#include <bits/stdc++.h>

using namespace std;

int N, Q;
char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		scanf("%s", A + 1);
		while(Q--) {
			int l, r; scanf("%d%d", &l, &r);
			bool ok = true;
			for(int i = r + 1; i <= N; i++) if(A[r] == A[i]) ok = false;
			for(int i = l - 1; i >= 1; i--) if(A[l] == A[i]) ok = false;
			puts(ok ? "NO" : "YES");
		}
	}
	return 0;
}