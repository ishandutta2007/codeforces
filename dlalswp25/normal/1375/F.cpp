#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Y = 10000000000;

ll X[4];
bool t[4];

int main() {
	scanf("%lld%lld%lld", &X[1], &X[2], &X[3]);
	puts("First"); fflush(stdout);
	printf("%lld\n", Y); fflush(stdout);
	int x; scanf("%d", &x); X[x] += Y;
	t[x] = true;

	ll s = 0; for(int i = 1; i <= 3; i++) s += X[i];
	ll mx = 0; for(int i = 1; i <= 3; i++) mx = max(mx, X[i]);

	ll Z = 3 * mx - s;
	printf("%lld\n", Z); fflush(stdout);
	scanf("%d", &x); X[x] += Z;
	printf("%lld\n", X[x] - mx); fflush(stdout);

	return 0;
}