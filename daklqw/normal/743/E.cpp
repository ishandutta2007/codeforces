#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1010
int n, sums[MAXN], f[MAXN][1 << 8], cnt[8], ans = -1;
vector<int> v[8];
void update(int & x, int y) {
	if (y > x) x = y;
}
bool judge(int x) {
	memset(f, -1, sizeof f);
	memset(cnt, 0, sizeof(int) * 8);
	f[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j != 1 << 8; ++j)
			if (~f[i][j]) {
				for (int k = 0; k != 8; ++k)
					if ((~j) & 1 << k) {
						int pos = cnt[k] + x - 1;
						if (pos < v[k].size()) update(f[v[k][pos]][j | 1 << k], f[i][j]);
						if (++pos < v[k].size()) update(f[v[k][pos]][j | 1 << k], f[i][j] + 1);
					}
			}
		if (i) ++cnt[sums[i]];
	}
	int t = -1;
	for (int i = 1; i <= n; ++i) update(t, f[i][(1 << 8) - 1]);
	if (~t) {update(ans, 8 * x + t); return true;}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &sums[i]);
		v[--sums[i]].push_back(i);
	}
	bool flag = false;
	for (int i = 0; i != 8; ++i) if (!v[i].size()) {flag = true; break;}
	if (flag) {
		int ans = 0;
		for (int i = 0; i != 8; ++i)
			if (v[i].size()) ++ans;
		printf("%d\n", ans);
		return 0;
	}
	int l = 0, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if(judge(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}