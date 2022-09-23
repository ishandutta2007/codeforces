#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

ll A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; ll K; scanf("%d%lld", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		sort(A + 1, A + N + 1);
		ll g = 0;
		for(int i = 2; i <= N; i++) g = gcd(g, A[i] - A[i - 1]);
		if(abs(K - A[1]) % g == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}