#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int ans = 1;	
		for(int i = 1; i < N + N; i++) {
			if(A[i] == '(' && A[i + 1] == '(') ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}