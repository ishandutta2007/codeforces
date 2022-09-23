#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[55];
char B[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		bool ok = true;
		for(int i = 0; i < M - 1; i++) if(A[N - i] != B[M - i]) ok = false;
		if(!ok) { puts("NO"); continue; }
		ok = false;
		for(int i = 1; i <= N - M + 1; i++) if(A[i] == B[1]) ok = true;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}