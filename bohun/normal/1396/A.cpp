#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()

using ll = long long;

using namespace std;

const int N = 1e5 + 10;

int n;
ll a[N];

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) scanf ("%lld", a + i);
	
	if (n == 1) {
		printf ("1 1\n");
		printf ("0\n");
		printf ("1 1\n");
		printf ("0\n");
		printf ("1 1\n");
		printf ("%lld\n", -a[1]);
		return 0;
	}
	
	printf ("1 %d\n", n - 1);
	for (int i = 1; i <= n - 1; ++i) {
		int r = a[i] % n;
		a[i] += (ll) (n - 1) * r;
		printf ("%lld ", (ll) (n - 1) * r);
	}
	printf ("\n");
	
	printf ("2 %d\n", n);
	for (int i = 2; i <= n; ++i) {
		int r = a[i] % n;
		a[i] += (ll) (n - 1) * r;
		printf ("%lld ", (ll) (n - 1) * r);
	}
	printf ("\n");
	
	printf ("1 %d\n", n);
	for (int i = 1; i <= n; ++i) {
		assert(a[i] % n == 0);
		printf ("%lld ", -a[i]);
	}
	
	return 0;
}