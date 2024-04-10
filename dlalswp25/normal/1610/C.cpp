#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d%d", &A[i], &B[i]);
		int l = 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int cnt = 0;
			for(int i = 1; i <= N; i++) {
				if(A[i] >= m - cnt - 1 && B[i] >= cnt) cnt++;
			}
			if(cnt < m) r = m - 1;
			else l = m + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}