#include <bits/stdc++.h>

using namespace std;

int N;
char A[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int cnt = 0;
		for(int i = 1; i <= N; i++) cnt += (A[i] == 'N');
		puts(cnt == 1 ? "NO" : "YES");
	}
	return 0;
}