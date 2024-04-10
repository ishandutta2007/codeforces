#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], chk[N], sz[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
		int cnt = 0;
		for (int i = 0; i < n; i++) chk[i] = 0;
		for (int i = 0; i < n; i++) if (!chk[i]) {
			int u = i;
			chk[i] = ++cnt;
			sz[cnt] = 1;
			while (!chk[a[u]]) {
				u = a[u];
				chk[u] = cnt;
				sz[cnt]++;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << sz[chk[i]] << " ";
		}
		cout << "\n";
	}
	return 0;
}