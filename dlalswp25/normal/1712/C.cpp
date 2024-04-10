#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int mn[101010];
int mx[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) mn[i] = mx[i] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(!mn[A[i]]) mn[A[i]] = i;
			mx[A[i]] = i;
		}

		int x = 0;
		for(int i = N - 1; i >= 1; i--) {
			if(A[i] > A[i + 1]) { x = i; break; }
		}
		if(!x) { puts("0"); continue; }

		int r = 0, ans = 0;
		for(int i = 1; i <= N; i++) {
			if(i == mn[A[i]]) { ans++; r = max(r, mx[A[i]]); }
			if(i == r && x <= r) { printf("%d\n", ans); break; }
		}
	}
	return 0;
}