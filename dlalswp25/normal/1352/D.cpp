#include <bits/stdc++.h>

using namespace std;

int A[1010];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int x = A[1], y = 0;
		int l = 2, r = N;

		bool bob = true;
		int bef = x;

		int mov = 1;
		while(l <= r) {
			int cur = 0;
			if(bob) {
				while(l <= r) {
					cur += A[r]; y += A[r]; r--;
					if(cur > bef) break;
				}
			}
			else {
				while(l <= r) {
					cur += A[l]; x += A[l]; l++;
					if(cur > bef) break;
				}
			}
			bef = cur;
			mov++;
			bob = !bob;
		}
		printf("%d %d %d\n", mov, x, y);
	}
	return 0;
}