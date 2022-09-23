#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 1000;

ll F[1010];

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N & 1) puts("0");
		else printf("%lld\n", F[N / 2] * F[N / 2] % MOD);
	}
	return 0;
}