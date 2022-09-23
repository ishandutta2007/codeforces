#include <bits/stdc++.h>

using namespace std;

char A[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int K; scanf("%d", &K);
		scanf("%s", A + 1);
		int x = 0, y = 0;
		for(int i = 1; i <= K; i++) {
			if(A[i] != '2' && A[i] != '3' && A[i] != '5' && A[i] != '7') {
				x = i; break; 
			}
		}
		if(x) { printf("1\n%c\n", A[x]); continue; }
		bool ok = false;
		for(int i = 1; i <= K; i++) {
			if(ok) break;
			for(int j = i + 1; j <= K; j++) {
				int n = (A[i] - '0') * 10 + (A[j] - '0');
				for(int k = 2; k * k <= n; k++) {
					if(n % k == 0) { ok = true; break; }
				}
				if(ok) { x = i; y = j; break; }
			}
		}
		printf("2\n%c%c\n", A[x], A[y]);
	}
	return 0;
}