#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 1000000;
const ll MOD = 998244353;

ll D[1010101];
ll S[1010101];
ll C[1010101];

int main() {
	for(int i = 1; i <= MX; i++) {
		for(int j = i; j <= MX; j += i) C[j]++;
	}

	D[1] = 1;
	S[1] = 1;
	for(int i = 2; i <= MX; i++) {
		D[i] = (S[i - 1] + C[i]) % MOD;
		S[i] = (S[i - 1] + D[i]) % MOD;
	}

	int N; scanf("%d", &N);
	printf("%lld\n", D[N]);

	return 0;
}