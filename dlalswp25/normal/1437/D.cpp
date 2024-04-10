#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int h = 0;
		int p = 2, l = 2;
		int m = 1;
		while(1) {
			int c = 0;
			while(p <= N) {
				p++;
				if(p > N) break;
				if(A[p - 1] > A[p]) c++;
				if(c >= m) break;
			}
			m = p - l;
			h++;
			l = p;
			if(l > N) break;
		}
		printf("%d\n", h);
	}
	return 0;
}