#include <bits/stdc++.h>

using namespace std;

int A[202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		bool ok = false;
		for(int i = 2; i <= N; i++) {
			if(abs(A[i] - A[i - 1]) > 1) {
				puts("YES");
				printf("%d %d\n", i - 1, i);
				ok = true;
				break;
			}
		}
		if(!ok) puts("NO");
	}
	return 0;
}