#include <bits/stdc++.h>

using namespace std;

bool chk[101];
int A[101];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		int mn = 987654321, id = 0;
		for(int j = 1; j <= N; j++) {
			if(chk[j]) continue;
			if(mn > A[j]) { mn = A[j]; id = j; }
		}
		if(!id) break;
		ans++;
		for(int j = 1; j <= N; j++) {
			if(A[j] % mn == 0) chk[j] = true;
		}
	}
	printf("%d\n", ans);

	return 0;
}