#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % N;
		a = a * a % N;
		b >>= 1;
	}
	return ret;
}
ll inv(ll x) {
	return pw(x, N - 2);
}

int main() {
	scanf("%d", &N);
	if(N == 4) {
		printf("YES\n1\n3\n2\n4\n"); return 0;
	}

	for(int i = 2; i * i <= N; i++) {
		if(N % i == 0) { puts("NO"); return 0; }
	}

	puts("YES");

	int x = 1;
	for(int i = 1; i < N; i++) {
		printf("%d\n", x);
		x = (i + 1) * inv(i) % N;
	}
	printf("%d\n", N);

	return 0;

}