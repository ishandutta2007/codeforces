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

const int N = 3e5 + 50;

int n, p[N], ans[N], cnt[N];

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) cnt[i] = ans[i] = 0;
	rep(i, 1, n) scanf("%d", p + i), cnt[p[i]]++;
	ans[1] = *max_element(cnt + 1, cnt + n + 1) == 1;
	int l = 1, r = n;
	per(i, 2, n) {
		int x = n - i + 1;
		if (!cnt[x]) break;
		ans[i] = 1;
		if (cnt[x] > 1) break;
		if (p[l] == x) l++;
		else if (p[r] == x) r--;
		else break;
	}
	rep(i, 1, n) printf("%d", ans[i]); puts("");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}