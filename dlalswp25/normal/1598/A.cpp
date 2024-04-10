#include <bits/stdc++.h>

using namespace std;

int N;
char A[2][105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A[0] + 1);
		scanf("%s", A[1] + 1);
		bool ok = true;
		for(int i = 1; i <= N; i++) if(A[0][i] == '1' && A[1][i] == '1') ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}