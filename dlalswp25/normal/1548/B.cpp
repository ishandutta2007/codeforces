#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[202020];
ll B[202020];
ll st[20][202020];

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i < N; i++) B[i] = abs(A[i + 1] - A[i]);

		if(N == 1) { puts("1"); continue; }

		for(int i = 1; i < N; i++) st[0][i] = B[i];

		for(int i = 1; i <= 19; i++) {
			for(int j = 1; j < N; j++) {
				if(j + (1 << i) - 1 >= N) {
					st[i][j] = 1; continue;
				}
				st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
			}
		}

		int ans = 0;
		for(int i = 1; i < N; i++) {
			ll cur = 0;
			int pos = i;
			for(int j = 19; j >= 0; j--) {
				if(pos >= N) break;
				ll g = gcd(cur, st[j][pos]);
				if(g == 1) continue;
				cur = g;
				pos += 1 << j;
			}
			ans = max(ans, pos - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}