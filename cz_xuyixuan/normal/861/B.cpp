#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
bool flg[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= 100; i++)
		flg[i] = true;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		for (int j = 1; j <= 100; j++)
			flg[j] &= (x - 1) / j + 1 == y;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++)
		if (flg[i]) {
			int tmp = (n - 1) / i + 1;
			if (ans && ans != tmp) ans = -1;
			else ans = tmp;
		}
	cout << ans << endl;
	return 0;
}