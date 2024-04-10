#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[101010];

ll f(int i) {
	if(A[i] == A[i + 1]) return 0;
	return (ll)i * (N - i);
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	ll ans = 0;
	for(int i = 1; i < N; i++) ans += f(i);
	while(M--) {
		int a, b; scanf("%d%d", &a, &b);
		if(a > 1) ans -= f(a - 1);
		if(a < N) ans -= f(a);
		A[a] = b;
		if(a > 1) ans += f(a - 1);
		if(a < N) ans += f(a);
		printf("%lld\n", ans + (ll)N * (N + 1) / 2);
	}
	return 0;
}