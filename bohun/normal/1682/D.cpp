#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

int T, n;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;
		vector<int> pos;
		rep(i, 0, n - 1) {
			if (s[i] == '1') {
				pos.push_back(i);
			}
		}

		int sz = int(pos.size());
		if (sz == 0 || sz % 2) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";

		vector<int> siz(n);

		auto f = [&](int a, int b) {
			siz[a] ^= 1;
			siz[b] ^= 1;
			cout << a + 1 << " " << b + 1 << endl;
		};

		auto add = [&](vector<int> v) {
			rep(i, 1, int(v.size()) - 1) {
				f(v[i - 1], v[i]);
			}
		};

		rep(j, 1, sz - 2) {
			vector<int> v = {pos[0]};
			rep(i, pos[j - 1] + 1, pos[j]) {
				v.push_back(i);
			}
			add(v);
		}

		vector<int> v = {pos[0]};
		rep(i, pos[sz - 2] + 1, pos[sz - 1] - 1) {
			v.push_back(i);
		}
		for (int i = (pos[0] - 1 + n) % n; i != pos[sz - 1]; i = (i - 1 + n) % n) {
			v.push_back(i);
		}
		v.push_back(pos[sz - 1]);
		add(v);

		rep(i, 0, n - 1) {
			assert((s[i] - '0') == siz[i]);
		}
	}

	return 0;
}