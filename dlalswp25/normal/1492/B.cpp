#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int pos[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			pos[A[i]] = i;
		}
		int p = N;
		int lft = N + 1;
		while(p >= 1) {
			if(pos[p] >= lft) { p--; continue; }
			for(int i = pos[p]; i < lft; i++) printf("%d ", A[i]);
			lft = pos[p];
		}
		puts("");
	}
	return 0;
}