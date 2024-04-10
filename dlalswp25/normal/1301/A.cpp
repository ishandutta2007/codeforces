#include <bits/stdc++.h>

using namespace std;

char A[105];
char B[105];
char C[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		scanf("%s", C + 1);
		int N = strlen(A + 1);
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i] != C[i] && B[i] != C[i]) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}