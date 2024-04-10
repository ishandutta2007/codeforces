#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
ll A[101010];
ll a1;
ll delta[101010];

ll f(ll x) {
	if(x >= 0) return (x + 1) / 2;
	return x / 2;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	a1 = A[1];
	for(int i = 1; i < N; i++) delta[i] = A[i + 1] - A[i];

	ll t = 0;
	for(int i = 1; i < N; i++) {
		if(delta[i] > 0) t += delta[i];
	}
	printf("%lld\n", f(a1 + t));

	scanf("%d", &Q);
	while(Q--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if(a == 1) a1 += c;
		else {
			if(delta[a - 1] > 0) t -= delta[a - 1];
			delta[a - 1] += c;
			if(delta[a - 1] > 0) t += delta[a - 1];
		}

		if(b != N) {
			if(delta[b] > 0) t -= delta[b];
			delta[b] -= c;
			if(delta[b] > 0) t += delta[b];
		}
		printf("%lld\n", f(a1 + t));
	}
	return 0;
}