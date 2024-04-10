#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, M;

ll D[101010];

int main() {
	scanf("%d%d", &N, &M);
	D[1] = 1; D[2] = 2;
	for(int i = 3; i <= 100000; i++) D[i] = (D[i - 1] + D[i - 2]) % MOD;

	printf("%lld\n", ((D[N] + D[M]) * 2 - 2) % MOD);

	return 0;
}