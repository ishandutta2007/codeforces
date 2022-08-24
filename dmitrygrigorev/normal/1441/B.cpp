#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;
vector<vector<int> > trans;

const int mod = 998244353;
const int N = 200007;

struct Vertex {
	int x;
	int y;
	pair<int, int> who;
};

Vertex dp[N][2];

bool cmp(Vertex &a, Vertex &b) {

	if (mp(a.x, a.y) != mp(b.x, b.y)) return (mp(a.x, a.y) < mp(b.x, b.y));
	return (a.who < b.who);

}

struct lex_compare {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return cmp(dp[lhs.x][lhs.y], dp[rhs.x][rhs.y]);
    }
};

int n;

const ll INF = 1e18;

vector<pair<ll, int> > kek;
vector<int> sp;

bool cmp2(int a, int b) {
	return (sp[a] < sp[b]);
}

void try_simple() {

	vector<ll> d(n, INF);
	d[0] = 0;

	ll res = INF;

	for (int it = 0; it < 32; ++it) {
		if (it % 2 == 0) {
			kek.clear();
			for (int i = 0; i < n; ++i) kek.pb(mp(d[i], i));
			sort(all(kek));

			sp.assign(n, -1);
			for (int i = 0; i < n; ++i) sp[kek[i].y] = i;

			for (auto& Q : gr) sort(Q.begin(), Q.end(), cmp2);

			vector<bool> used(n, false);
			int u = 0;

			queue<pair<ll, int> > tet;
			while (tet.size() || u < n) {
				if (!tet.size()) {
					if (used[kek[u].y]) {
						u++;
						continue;
					}
					used[kek[u].y] = true; 
					tet.push(kek[u++]);
				}

				auto W = tet.front();
				tet.pop();
				used[W.y] = true;

				for (auto to : gr[W.y]) {
					if (used[to]) continue;
					if (d[W.y] + 1 >= d[to]) continue;
					d[to] = d[W.y] + 1;

					while (u < n && kek[u].x < d[to]) {
						if (used[kek[u].y]) {
							u++;
							continue;
						}
						used[kek[u].y] = true; 
						tet.push(kek[u++]);
					}

					if (used[to]) continue;
					used[to] = true;
					tet.push(mp(d[to], to));
				}
			}
			res = min(res, d[n-1]);

			ll cost = (1LL<<it);
			for (int i = 0; i < n; ++i) {
				d[i] += cost;
			}

		}

		else {
			kek.clear();
			for (int i = 0; i < n; ++i) kek.pb(mp(d[i], i));
			sort(all(kek));

			sp.assign(n, -1);
			for (int i = 0; i < n; ++i) sp[kek[i].y] = i;

			for (auto& Q : trans) sort(Q.begin(), Q.end(), cmp2);

			vector<bool> used(n, false);
			int u = 0;

			queue<pair<ll, int> > tet;
			while (tet.size() || u < n) {
				if (!tet.size()) {
					if (used[kek[u].y]) {
						u++;
						continue;
					}
					used[kek[u].y] = true; 
					tet.push(kek[u++]);
				}

				auto W = tet.front();
				tet.pop();
				used[W.y] = true;

				for (auto to : trans[W.y]) {
					if (used[to]) continue;
					if (d[W.y] + 1 >= d[to]) continue;
					d[to] = d[W.y] + 1;

					while (u < n && kek[u].x < d[to]) {
						if (used[kek[u].y]) {
							u++;
							continue;
						}
						used[kek[u].y] = true; 
						tet.push(kek[u++]);
					}

					if (used[to]) continue;
					used[to] = true;
					tet.push(mp(d[to], to));
				}
			}
			res = min(res, d[n-1]);

			ll cost = (1LL<<it);
			for (int i = 0; i < n; ++i) {
				d[i] += cost;
			}
		}

	}

	if (res < INF) {
		cout << res % mod;
		exit(0);
	}

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	gr.assign(n, {});
	trans.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].pb(v);
		trans[v].pb(u);
	}

	try_simple();

	set<pair<int, int>, lex_compare> ms;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = {1000000000, 0, mp(i, j)};
		}
	}

	dp[0][0] = {0, 0, mp(0, 0)};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			ms.insert(mp(i, j));
		}
	}

	while (ms.size()) {
		auto W = (*ms.begin());
		ms.erase(ms.find(W));

		int a = W.x, b = W.y;
		if (b == 0) {
			for (auto to : gr[a]) {
				auto ans = dp[a][b];
				ans.y++;

				if (cmp(ans, dp[to][b])) {
					ms.erase(ms.find(mp(to, b)));
					dp[to][b].x = ans.x;
					dp[to][b].y = ans.y;
					ms.insert(mp(to, b));
				}
			} 
			for (auto to : trans[a]) {
				auto ans = dp[a][b];
				ans.x++;
				ans.y++;

				if (cmp(ans, dp[to][1-b])) {
					ms.erase(ms.find(mp(to, 1-b)));
					dp[to][1-b].x = ans.x;
					dp[to][1-b].y = ans.y;
					ms.insert(mp(to, 1-b));
				}
			} 
		}

		else {
			for (auto to : trans[a]) {
				auto ans = dp[a][b];
				ans.y++;

				if (cmp(ans, dp[to][b])) {
					ms.erase(ms.find(mp(to, b)));
					dp[to][b].x = ans.x;
					dp[to][b].y = ans.y;
					ms.insert(mp(to, b));
				}
			} 
			for (auto to : gr[a]) {
				auto ans = dp[a][b];
				ans.x++;
				ans.y++;

				if (cmp(ans, dp[to][1-b])) {
					ms.erase(ms.find(mp(to, 1-b)));
					dp[to][1-b].x = ans.x;
					dp[to][1-b].y = ans.y;
					ms.insert(mp(to, 1-b));
				}
			} 
		}

	}

	if (cmp(dp[n-1][1], dp[n-1][0])) swap(dp[n-1][0], dp[n-1][1]);

	int res = 1;
	for (int i = 0; i < dp[n-1][0].x; ++i) {
		res *= 2;
		if (res >= mod) res -= mod;
	}

	res--;
	if (res < 0) res += mod;

	res += dp[n-1][0].y;
	cout << (res % mod);



}