#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

bool chk(int a, int b, int c) {
	return (a <= b && b <= c) || (a >= b && b >= c);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int ans = 0;
		int l = 1;
		for(int i = 1; i <= N; i++) {
			if(i > 2) {
				if(chk(A[i - 2], A[i - 1], A[i])) l = i - 1;
				if(i > 3 && l <= i - 3) {
					if(chk(A[i - 3], A[i - 2], A[i])) l = i - 2;
					if(chk(A[i - 3], A[i - 1], A[i])) l = i - 2;
				}
			}
			ans += (i - l + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}