#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

const int N = 200200;
int n, m, a[N], b[N], vis[N], id, cnt[N];
pair<int, int> E[N];
deque<pair<int, int>> e[N];
vector<int> res;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) {
		int x, y;
		cin >> x >> y;
		E[i] = {x, y};
		e[x].push_back({y, i});
		e[y].push_back({x, i});
	} 

	rep(i, 1, n) {
		if (vis[i]) continue;

		vector<int> p;

		int x = i;
		while (!vis[x]) {
			p.push_back(x);
			vis[x] = 1;
			b[x] = ++id;
			x = a[x];
		}

		if (p.size() == 1) continue;

		queue<int> Q;
		auto inc = [&](int x) {
			cnt[x]++;
			if (cnt[x] == 2) {
				Q.push(x);
			}
		};

		for (auto x : p) {
			sort(e[x].begin(), e[x].end(), [&](auto p, auto q) {
				return (b[p.first] - b[x] + n) % n < (b[q.first] - b[x] + n) % n;
			});
			inc(e[x][0].second);
		}

		while (!Q.empty()) {
			int id = Q.front();
			Q.pop();

			res.push_back(id);
			auto [x, y] = E[id];
			e[x].pop_front();
			e[y].pop_front();
			if (!e[x].empty()) inc(e[x][0].second);
			if (!e[y].empty()) inc(e[y][0].second);
		}

	}

	for (auto x : res) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}