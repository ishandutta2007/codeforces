#include <bits/stdc++.h>
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define cat(x) cerr << #x << " = " << x << endl
#define ss(x) (int) x.size()
using ll = long long;

using namespace std;

int n, a[100005], b[100005];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		int m = 1e9;
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", a + i);
			m = min(m, a[i]);
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			if (a[i] % m && a[i] != b[i]) {
				printf ("NO\n");
				flag = true;
				break;
			}
		}
		if (!flag) printf ("YES\n");
	}
	return 0;
}