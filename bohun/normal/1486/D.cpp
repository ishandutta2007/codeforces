#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, k, a[N], b[N];

bool ok(int x) {
	int s = 0;
	rep(i, 1, n) {
		s += a[i] >= x ? 1 : -1;
		b[i] = min(b[i - 1], s);
		if (i >= k && s - b[i - k] > 0) return 1;
	}
	return 0;
}
 
int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", a + i);
	int l = 1, r = n;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (ok(m)) l = m;
		else r = m - 1;
	}
	printf("%d\n", l);
	return 0;
}