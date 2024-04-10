#include <bits/stdc++.h>

using namespace std;

int T;
int A[151515];

int main() {
	scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		int mn = A[N];
		int ans = 0;
		for(int i = N - 1; i >= 1; i--) {
			if(mn < A[i]) ans++;
			mn = min(mn, A[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}