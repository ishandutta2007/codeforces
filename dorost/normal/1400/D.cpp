/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 3012;
int a[N], p[N][N], s[N][N];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < n + 10; i++)
		for (int j = 0; j < n + 10; j++)
			p[i][j] = 0, s[i][j] = 0;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= n + 10; j++) {
			s[i][j] = s[i + 1][j];
		}
		s[i][a[i + 1]]++;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n + 10; j++) {
			p[i][j] = p[i - 1][j];
		}
		p[i][a[i - 1]]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += (p[i][a[j]] * s[j][a[i]]);
		}
	}
	printf("%lld ", ans);
}

int32_t main() {
	int t = 1;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}