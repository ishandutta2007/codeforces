#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> H[2];

int P;

int modExp(int a, int n, int mo) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % mo) if (n & 1) ret = ret * 1LL * a % mo;
	return ret;
}

int op(int x, int y) {
	return y == 1 ? (x + 1) % P : y == 2 ? (x + P - 1) % P : modExp(x, P - 2, P);
}

int main() {
	ios::sync_with_stdio(0);
	int u, v; cin >> u >> v >> P;
	if (u == v) return puts("0"), 0;
	int S[2];
	S[0] = u, S[1] = v;
	vector<int> vec[2][2];
	int cur = 0, now[2] = {0};
	for (int i = 0; i < 2; i++) {
		vec[i][now[i]].push_back(S[i]);
		H[i][S[i]] = 1;
	}
	while (true) {
		vec[cur][!now[cur]].clear();
		for (int e : vec[cur][now[cur]]) {
			if (H[!cur].count(e)) {
				u = v = e;
				vector<int> ans;
				while (u != S[0]) {
					int md = H[0][u];
					ans.push_back(md);
					u = op(u, 3 - md % 3);
				}
				reverse(ans.begin(), ans.end());
				while (v != S[1]) {
					int md = H[1][v];
					ans.push_back(3 - md % 3);
					v = op(v, 3 - md % 3);
				}
				cout << ans.size() << endl;
				for (int f : ans) cout << f << " ";
				cout << endl;
				return 0;
			}
			for (int i = 1; i <= 3; i++) {
				v = op(e, i);
				if (!H[cur].count(v)) {
					H[cur][v] = i;
					vec[cur][!now[cur]].push_back(v);
				}
			}
		}
		now[cur] ^= 1, cur ^= 1;
	}
	return 0;
}