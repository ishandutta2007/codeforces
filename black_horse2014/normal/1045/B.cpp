#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], b[N], c[N], f[N], g[N];

void KMP(int *c, int n, int *f) {
	f[1] = 0;
	for (int j = 0, i = 1; i < n; i++) {
		while (j > 0 && c[i+1] != c[j+1]) j = f[j];
		if (c[i+1] == c[j+1]) j++;
		f[i+1] = j;
	}
}

int match(int *b, int *c, int n, int *f) {
	int j = 0;
	for (int i = 1; i <= n; i++) {
		while (j > 0 && c[j+1] != b[i]) j = f[j];
		if (c[j+1] == b[i]) j++;
	}
	return j;
}

int chk[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) b[i] = a[i+1] - a[i];
	for (int i = 1; i < n; i++) c[n-i] = b[i];
	KMP(c, n-1, f);
	KMP(b, n-1, g);
	int x = match(b, c, n-1, f);
	int y = match(c, b, n-1, g);
	vector<int> ans;
	if (x == n-1) ans.push_back((a[1] + a[n]) % m);
	while (x > 0) {
		chk[n-1-x] |= 1;
		x = f[x];
	}
	chk[n-1] |= 1;
	while (y > 0) {
		chk[y+1] |= 2;
		y = g[y];
	}
	chk[1] |= 2;
	for (int i = 1; i <= n-1; i++) {
		if (chk[i] == 3) {
			if ((a[1] + a[i]) % m == (a[i+1] + a[n]) % m) {
				ans.push_back((a[1] + a[i]) % m);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int t : ans) cout << t << " ";
	cout << endl;
	return 0;
}