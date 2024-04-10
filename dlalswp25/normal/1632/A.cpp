#include <bits/stdc++.h>

using namespace std;

int N;
char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		if(N >= 3) puts("NO");
		else if(N == 1) puts("YES");
		else puts(A[1] == A[2] ? "NO" : "YES");
	}
	return 0;
}