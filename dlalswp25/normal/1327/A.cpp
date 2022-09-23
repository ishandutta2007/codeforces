#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll N, K; scanf("%lld%lld", &N, &K);
		if((N & 1) != (K & 1)) puts("NO");
		else if(N < K * K) puts("NO");
		else puts("YES");
	}
	return 0;
}