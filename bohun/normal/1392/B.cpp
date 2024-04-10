#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;

using namespace std;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n;
		ll k;
		scanf ("%d%lld", &n, &k);
		vector <int> a(n);
		for (auto &it : a) scanf ("%d", &it);
		int d = -2e9;
		for (int i = 0; i < n; ++i) d = max(d, a[i]);
		for (int i = 0; i < n; ++i) a[i] = d - a[i];
		k = (k - 1) % 2;
		while (k--) {
			d = -2e9;
			for (int i = 0; i < n; ++i) d = max(d, a[i]);
			for (int i = 0; i < n; ++i) a[i] = d - a[i];
		}
		for (int i = 0; i < n; ++i) printf ("%d ", a[i]);
		printf ("\n");
	}																			
	return 0;
}