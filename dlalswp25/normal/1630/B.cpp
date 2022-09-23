#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[202020];
int cnt[202020];
int X, Y;

bool solve(int m) {
	int s = 0;
	for(int i = 1; i <= m + 1; i++) s += cnt[i];
	if(s - (N - s) >= K) {
		X = 1; Y = m + 1;
		return true;
	}
	for(int i = 2; i + m <= N; i++) {
		s -= cnt[i - 1];
		s += cnt[i + m];
		if(s - (N - s) >= K) {
			X = i; Y = m + i;
			return true;
		}
	}
	return false;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			cnt[A[i]]++;
		}

		int x = 0, y = 0;
		int l = 0, r = N - 1;
		while(l <= r) {
			int m = l + r >> 1;
			if(solve(m)) r = m - 1;
			else l = m + 1;
		}

		solve(l);
		printf("%d %d\n", X, Y);
		int lft = 1;
		int s = 0;
		int rem = K;
		for(int i = 1; i <= N; i++) {
			if(rem == 1) break;
			if(X <= A[i] && A[i] <= Y) s++;
			else s--;
			if(s > 0) {
				printf("%d %d\n", lft, i);
				lft = i + 1;
				rem--;
				s = 0;
			}
		}
		if(rem) printf("%d %d\n", lft, N);
	}
	return 0;
}