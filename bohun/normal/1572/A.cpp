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

int n, cnt[N], dis[N];
vector<int> e[N];

void solve() {
	cin >> n;
	FOR(i, n) {
		int sz;
		cin >> sz;
		while (sz--) {
			int x;
			cin >> x;
			x--;
			cnt[i]++;
			e[x].push_back(i);
		}
	}

	queue<int> q;
	FOR(i, n) {
		dis[i] = -1;
		if (cnt[i] == 0) {
			q.push(i);
			dis[i] = 0;
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			cnt[v]--;
			dis[v] = max(dis[v], dis[u] + (v < u));
			if (cnt[v] == 0)
				q.push(v);
		}
	}

	if (*max_element(cnt, cnt + n) > 0) {
		cout << "-1\n";
	}
	else {
		cout << 1 + *max_element(dis, dis + n) << '\n';
	}

	FOR(i, n) {
		e[i].clear();
		cnt[i] = 0;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}