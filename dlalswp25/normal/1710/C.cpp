#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
char A[202020];
ll D[202020][8][8];
int U[8] = {-1, 0, 1, 2, 2, 1, 0, -1};

ll f(int n, int s, int t) {
	if(n == N) return !t;
	ll& ret = D[n][s][t];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < 8; i++) {
		bool ok = true;
		for(int j = 0; j < 3; j++) {
			if(i >> j & 1) {
				if(!(s >> j & 1) && A[n] == '0') ok = false;
			}
		}
		if(!ok) continue;
		int ns = s, nt = t;
		if(A[n] == '1') {
			for(int j = 0; j < 3; j++) {
				if(s >> j & 1) continue;
				if(!(i >> j & 1)) ns |= 1 << j;
			}
		}
		if(U[i] != -1) nt &= ~(1 << U[i]);
		ret = (ret + f(n + 1, ns, nt)) % MOD;
	}
	return ret;
}

int main() {
	scanf("%s", A);
	N = strlen(A);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 8; j++) {
			for(int k = 0; k < 8; k++) {
				D[i][j][k] = -1;
			}
		}
	}
	printf("%lld\n", f(0, 0, 7));
	return 0;
}