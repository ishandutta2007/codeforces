#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			p[--a] = i;
		}
		vector<int> cnt(n);
		for (int i = 0; i < n; i++) 
			cnt[(p[i] - i + n) % n]++;
		vector<int> res;
		for (int shift = 0; shift < n; shift++) {
			if (3 * cnt[shift] >= n) {
				vector<int> a(n);
				for (int i = 0; i < n; i++)
					a[(i + shift) % n] = p[i];
				vector<int> vis(n);
				int c = 0;
				for (int i = 0; i < n; i++) {
					if (vis[i]) continue;
					int x = i;
					while (!vis[x]) {
						vis[x] = 1;
						x = a[x];
					}
					c++;
				}
				if (n - c <= m)
					res.push_back(shift);
			}
		}
		cout << res.size() << " ";
		for (auto x : res)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}