#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];
ll out;

void solve() {
	out = 0;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", a + i);
		if (i > 1 && a[i - 1] > a[i]) out += a[i - 1] - a[i];
	}
	printf ("%lld\n", out);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}																			
	return 0;
}