#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define MAXN 300010
LL n, m, a[MAXN], b[MAXN], cnt1 = 0, cnt2 = 0, cur1 = 0, cur2 = 0, ans = -1, t0t;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i], t0t += a[i];
	cin >> m; for (int i = 1; i <= m; ++i) cin >> b[i], t0t -= b[i];
	if (t0t) { cout << "-1" << endl; return 0; }
	while (cur1 <= n) {
		if (cnt1 == cnt2) cnt1 = a[++cur1], cnt2 = b[++cur2], ++ans;
		else if (cnt1 > cnt2) cnt2 += b[++cur2];
		else cnt1 += a[++cur1];
	}
	cout << ans << endl;
	return 0;
}