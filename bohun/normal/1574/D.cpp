//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 200200;
int n, m;
ll suf[11], res = 0;
vector<vector<int>> a;
vector<int> opt;

void solve(int p, ll sum, vector<vector<int>> banned, vector<int> ass) {
	if (banned.empty()) {
		if (sum + suf[p] > res) {
			res = sum + suf[p];
			rep(i, p, n)
				ass[i] = sz(a[i]) - 1;
			opt = ass;
		}
		return;
	}
	if (p == n)
		return;
	set<int> s;
	for (int i = 0; i < sz(banned);) {
		vector<vector<int>> q;
		int j = i;
		while (j < sz(banned) && banned[i][p] == banned[j][p])
			q.push_back(banned[j++]);

		ass[p] = banned[i][p];
		solve(p + 1, sum + a[p][banned[i][p]], q, ass);
		s.insert(banned[i][p]);
		i = j;
	}
	int last = sz(a[p]) - 1;
	while (last >= 0 && s.count(last))
		last--;
	if (last >= 0) {
		ass[p] = last;
		solve(p + 1, sum + a[p][last], {}, ass);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	a.resize(n);
	FOR(i, n) {
		int sz;
		cin >> sz;
		a[i].resize(sz);
		for (auto &x : a[i])
			cin >> x;
	}

	per(i, 0, n)
		suf[i] = suf[i + 1] + a[i].back();

	cin >> m;
	vector<vector<int>> banned;
	while (m--) {
		vector<int> cur;
		FOR(q, n) {
			int x;
			cin >> x;
			x--;
			cur.push_back(x);
		}
		banned.push_back(cur);
	}

	sort(banned.begin(), banned.end());
	vector<int> res(n, 0);
	solve(0, 0, banned, res);
	for (auto x : opt)
		cout << x + 1 << ' ';
	return 0;
}