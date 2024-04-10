#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

const int N = 20111;

int n, vis[N], res[N];

void solve() {
	cin >> n;
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, n) {
		if (!vis[i]) {
			vector<int> c;
			while (1) {
				cout << "? " << i << endl;
				int x;
				cin >> x;
				if (vis[x]) break;
				vis[x] = 1;
				c.push_back(x);
			}
			rep(j, 0, c.size() - 1)
				res[c[j]] = c[(j + 1) % c.size()];
		}
	}
	cout << "! ";
	rep(i, 1, n) cout << res[i] << " ";
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}