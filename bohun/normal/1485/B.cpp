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

const int N = 1 << 19;

int n, q, k, a[N];
ll b[N];

int main() {
	scanf("%d%d%d", &n, &q, &k);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) b[i] = b[i - 1] + a[i + 1] - a[i - 1] - 2;
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r) {
			printf("%d\n", k - 1);
			continue;
		}
		printf("%lld\n", b[r - 1] - b[l] + a[l + 1] - 2 + (k - a[r - 1] - 1));
	}
	
	return 0;
}