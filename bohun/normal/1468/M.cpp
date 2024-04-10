#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 200200;

int n, a[N], cnt[N];
vector<int> v[N], id[N];

void solve() {
	cin >> n;
	int top = 0;
	rep(i, 1, n + 1) {
		int sz;
		cin >> sz;
		v[i].clear();
		while (sz--) {
			int x;
			cin >> x;
			a[top++] = x;
			v[i].push_back(x);
		}
	}

	sort(a, a + top);
	rep(i, 1, n + 1) 
		for (auto &x : v[i])
			x = lower_bound(a, a + top, x) - a;

	rep(i, 0, top)
		cnt[i] = 0, id[i].clear();

	rep(i, 1, n + 1) {
		if (int(v[i].size()) > 400) {
			for (auto x : v[i])
				cnt[x]++;
			rep(j, 1, n + 1) {
				if (i != j) {
					int res = 0;
					for (auto x : v[j])
						res += cnt[x] > 0;
					if (res >= 2) {
						cout << i << " " << j << "\n";
						return;
					}
				}
			}
			for (auto x : v[i])
				cnt[x]--;
		}
		else {
			for (auto x : v[i])
				id[x].push_back(i);
		}
	}
	
	rep(x, 0, top) {
		rep(r, 0, 2) {
			for (auto i : id[x]) {
				for (auto j : v[i]) {
					if (j == x)
						continue;
					if (r == 0) {
						if (cnt[j]) {
							cout << cnt[j] << " " << i << "\n";
							return;
						}
						cnt[j] = i;
					}
					else {
						cnt[j] = 0;
					}
				}
			}
		}
	}

	cout << "-1\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}