#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int Q;
ll N, M;
ll ans[11];

int main() {
	scanf("%d", &Q);
	while(Q--) {
		scanf("%lld%lld", &N, &M);

		for(int i = 1; i <= 10; i++) ans[i] = ans[i - 1] + M * i % 10;
		ll t = N / M;

		printf("%lld\n", t / 10 * ans[10] + ans[t % 10]);
	}

	return 0;
}