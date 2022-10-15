#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;
const int M = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M) {
		return a - M;
	}
	if (a < 0) {
		return a + M;
	}
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

struct Data {
	int lasth;
	int cnt;
};

const int N = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
int h;
int n;
int cntbars;
vector<Data> que[N];

pair<int, int> tree[4 * N];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v] = { INF, tl };
	}
	else {
		int tm = (tl + tr) / 2;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);
		tree[v] = min(tree[2 * v], tree[2 * v + 1]);
	}
}

void upd(int v, int tl, int tr, int i, int x) {
	if (tr < i || i < tl) return;
	if (tl == tr) {
		tree[v].first = x;
		return;
	}
	int tm = (tl + tr) / 2;
	upd(2 * v, tl, tm, i, x);
	upd(2 * v + 1, tm + 1, tr, i, x);
	tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (tr < l || r < tl) return { INF, INF };
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void build() {
	build(1, 1, n);
}

void upd(int i, int x) {
	upd(1, 1, n, i, x);
}

int get(int l, int r) {
	return get(1, 1, n, l, r).second;
}


signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	cin >> h >> n >> cntbars;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		que[i].push_back({ h + 1, 1 });
		upd(i, h + 1);
	}
	vector<vector<int>> bars(cntbars, vector<int>(4, 0));
	for (auto& v : bars) {
		for (auto& x : v) {
			cin >> x;
		}
	}
	sort(bars.rbegin(), bars.rend());
	for (auto& it_bar : bars) {
		assert((int)it_bar.size() == 4);
		int u = it_bar[0];
		int l = it_bar[1];
		int r = it_bar[2];
		int s = it_bar[3];

		int limit = min(h + 1, u + s);

		int gain = 0;

		while (1) {
			int j = get(l, r);
			if (l <= j && j <= r && !que[j].empty() && que[j].back().lasth <= limit) {
				addup(gain, que[j].back().cnt);
				que[j].pop_back();
				if (!que[j].empty()) {
					upd(j, que[j].back().lasth);
				}
				else {
					upd(j, INF);
				}
			}
			else {
				break;
			}
		}

		if (!gain) continue;

		if (l == 1) {
			assert(r < n);
			que[r + 1].push_back({ u, mul(2, gain) });
			upd(r + 1, u);
			continue;
		}

		if (r == n) {
			assert(1 < l);
			que[l - 1].push_back({ u, mul(2, gain) });
			upd(l - 1, u);
			continue;
		}
		assert(1 < l && l <= r && r < n);
		que[l - 1].push_back({ u, gain });
		que[r + 1].push_back({ u, gain });

		upd(l - 1, u);
		upd(r + 1, u);
	}
	int sol = 0;
	for (int i = 1; i <= n; i++) {
		for (auto& it : que[i]) {
			addup(sol, it.cnt);
		}
	}
	cout << sol << "\n";
}