#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int c[N], k[N], cnt[N];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &k[i]);
	int sum = 0;
	for (int i = 1; i <= m; i++) sum += k[i];
	for (int i = 1; i <= n; i++) cnt[c[i]]++;
	for (int i = 1; i <= m; i++) if (cnt[i] < k[i]) return puts("-1"), 0;
	int st = 1, en = n;
	while (st < en) {
		int md = st + en >> 1;
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= md; i++) cnt[c[i]]++;
		int flg = 0;
		for (int i = 1; i <= m; i++) {
			if (cnt[i] < k[i]) {
				flg = 1;
				break;
			}
		}
		if (flg) st = md + 1;
		else en = md;
	}
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= st; i++) cnt[c[i]]++;
	int ans = n;
	int j = st;
	ans = min(ans, j - sum);
	for (int i = 1; i <= n; i++) {
		cnt[c[i]]--;
		if (cnt[c[i]] < k[c[i]]) {
			while (++j) {
				cnt[c[j]]++;
				if (j > n || c[j] == c[i]) break;
			}
			if (j > n) break;
		}
		ans = min(ans, j - i - sum);
	}
	cout << ans << endl;
	return 0;
}