#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int mn = 0, mx = 0, mxi;
		int s = 0;
		for(int i = 1; i <= 2 * N; i++) {
			if(A[i] == '(') s++;
			else s--;
			mn = min(mn, s);
			if(mx < s) { mx = s; mxi = i; }
		}
		if(mn >= 0) { puts("0"); continue; }
		if(mx == 0) {
			printf("1\n%d %d\n", 1, 2 * N);
			continue;
		}
		int lmx = 0, li = 0;
		s = 0;
		for(int i = 1; i <= 2 * N; i++) {
			if(A[i] == '(') s++;
			else s--;
			if(s < 0) break;
			if(lmx < s) { lmx = s; li = i; }
		}
		int rmx = 0, ri = 2 * N;
		s = 0;
		for(int i = 2 * N; i >= 1; i--) {
			if(A[i] == '(') s--;
			else s++;
			if(s < 0) break;
			if(rmx < s) { rmx = s; ri = i - 1; }
		}
		if(lmx >= (mx - rmx)) {
			puts("1");
			printf("%d %d\n", li + 1, ri);
			continue;
		}
		puts("2");
		printf("%d %d\n%d %d\n", 1, mxi, mxi + 1, 2 * N);
	}
	return 0;
}