#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[1010][1010];

ll sq(ll x) {
	ll l = 1, r = 1000000000;
	while(l <= r) {
		ll m = l + r >> 1;
		if(m * m > x) r = m - 1;
		else l = m + 1;
	}
	return r;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%lld", &A[i][j]);
		}
	}

	ll x = A[1][2] * A[1][3] / A[2][3];
	x = sq(x);
	for(int i = 1; i <= N; i++) {
		printf("%lld ", x);
		x = A[i][i + 1] / x;
	}
	puts("");

	return 0;
}