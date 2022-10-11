#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, A, B, deg[1 << 19], fact[1 << 19];

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = (1LL * fact[i - 1] * i) % 998244353LL;
}

int main() {
	scanf("%lld", &N); init();
	for (int i = 0; i < N - 1; i++) {
		scanf("%lld%lld", &A, &B);
		deg[A]++; deg[B]++;
	}
	long long V = N, mod = 998244353;
	for (int i = 1; i <= N; i++) { V *= fact[deg[i]]; V %= mod; }
	cout << V << endl;
	return 0;
}