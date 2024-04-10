#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int n0 = 0, n1 = 0;
		for(int i = 1; i <= N; i++) (A[i] == '0' ? n0 : n1)++;
		int l = 0, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int p0 = 1, p1 = 1;
			int c0 = 0, c1 = 0;
			bool ok = false;
			for(int i = 1; i <= N; i++) {
				while(p0 <= N && c0 <= m) {
					if(A[p0] == '0') c0++;
					p0++;
				}
				if(c0 <= m) p0 = N + 2;
				while(p1 <= N && c1 < n1 - m) {
					if(A[p1] == '1') c1++;
					p1++;
				}
				if(c1 < n1 - m) break;
				if(p1 < p0) ok = true;
				(A[i] == '0' ? c0 : c1)--;
			}
			if(ok) r = m - 1;
			else l = m + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}