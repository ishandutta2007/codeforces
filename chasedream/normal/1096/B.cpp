#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
char a[200005];
int n;
ll l, r, t1 = 1, t2 = 1;

int main() {
	scanf("%d\n", &n);
	scanf("%s", a + 1);
	
	bool f = true;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[1]) {
			f = false;
			break;
		}
	}
	if (f) {
		printf("%lld\n", ((ll)n * (n + 1) / 2) % mod);
		return 0;
	}
	l = 1, r = n;
	while (l < n - 1 && a[l] == a[l + 1]) l++, t1++;
	while (r > 2 && a[r] == a[r - 1]) r--, t2++;
//	printf("%lld %lld %lld %lld\n", l, r, t1, t2);

	if (a[1] == a[n]) printf("%d\n", (t1 + 1) * (t2 + 1) % mod);
	else printf("%lld\n", (t1 + 1 + t2) % mod);
	return 0;
}