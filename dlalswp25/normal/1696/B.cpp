#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mn = N + 1, mx = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i]) { mn = min(mn, i); mx = max(mx, i); }
		}
		if(!mx) puts("0");
		else {
			bool ok = true;
			for(int i = mn; i <= mx; i++) if(!A[i]) ok = false;
			puts(ok ? "1" : "2");
		}
	}
	return 0;
}