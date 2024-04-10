#include <bits/stdc++.h>

using namespace std;

bool ok[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int A, B; scanf("%d%d", &A, &B);
		int N = A + B;
		for(int i = 0; i <= N; i++) ok[i] = false;
		int sa = (N + 1) / 2, sb = N / 2;
		if(sa > A) {
			int c = sa - A;
			for(int i = 0; i <= A; i++) {
				ok[c] = true;
				c += 2;
			}
		}
		else {
			int c = A - sa;
			for(int i = 0; i <= sb - (A - sa); i++) {
				ok[c] = true;
				c += 2;
			}
		}

		sa = N / 2; sb = (N + 1) / 2;
		if(sa > A) {
			int c = sa - A;
			for(int i = 0; i <= A; i++) {
				ok[c] = true;
				c += 2;
			}
		}
		else {
			int c = A - sa;
			for(int i = 0; i <= sb - (A - sa); i++) {
				ok[c] = true;
				c += 2;
			}
		}

		int ans = 0;
		for(int i = 0; i <= N; i++) ans += ok[i];
		printf("%d\n", ans);
		for(int i = 0; i <= N; i++) {
			if(ok[i]) printf("%d ", i);
		}
		puts("");
	}
	return 0;
}