#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll D[606060];
int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int b; scanf("%d", &b);
		D[i - b + 400000] += b;
	}
	ll ans = 0;
	for(int i = 1; i <= 600000; i++) ans = max(ans, D[i]);
	printf("%lld\n", ans);
	return 0;
}