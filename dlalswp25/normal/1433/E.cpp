#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int main() {
	scanf("%d", &N);
	ll ans = 1;
	for(int i = N / 2 + 1; i <= N; i++) ans *= i;
	ans /= N;
	for(int i = 1; i < N / 2; i++) ans *= i;
	printf("%lld\n", ans);
	return 0;
}