#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N], b[N];
int n, tot, ans;
map <int, map<int, int> > mp;

int gcd(int p1, int p2) {
	return p2 ? gcd(p2, p1 % p2) : p1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		if (!a[i] && !b[i]) tot++; // d * 0 + 0
		else if (a[i]) { // d * (!0) + *
			int g = gcd(a[i], b[i]);
			a[i] /= g, b[i] /= g;
			ans = max(ans, ++mp[a[i]][b[i]]);
		}
	}
	printf("%d\n", ans + tot);
	return 0;
}