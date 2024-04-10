#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair

using ll = long long;
using namespace std;

const int N = 1 << 17;

int n, a[N], cnt[N];

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) cnt[i] = 0;
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) {
		if (i == 1 || a[i - 1] == a[i]) cnt[a[i]]++;
		if (i == n || a[i + 1] == a[i]) cnt[a[i]]++;
	}
	int x = max_element(cnt + 1, cnt + n + 1) - cnt, s = 1, e = 0;
	rep(i, 2, n) {
		if (a[i - 1] != x && a[i] != x && a[i - 1] != a[i]) e++;
		if (a[i - 1] == a[i]) s++;
	}
	while (cnt[x] - s > 1 && e > 0) {
		s++;
		e--;
	}
	printf("%d\n", cnt[x] - s > 1 ? -1 : s - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}