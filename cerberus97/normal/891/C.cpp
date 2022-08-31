/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10, inf = 2 * N;

struct edge {
	int u, v, w;
	bool operator<(const edge& other) {
		return this->w < other.w;
	}
};

int parent[N], temp[N], depth[N], temp_depth[N];
bool ans[N], upd[N], upd_depth[N];
// vector <edge> all;
map <pii, vector <int>> mp;
stack <int> st, st_depth;
edge e[N];

void dsu_join(int i, int j, bool p);
int dsu_find(int i, bool p);
bool dsu_check(int i, int j, bool p);
int dsu_get(int i, bool p);
void dsu_set(int i, int j, bool p);
void dsu_reset();
int get_depth(int i, bool p);
void set_depth(int i, int j, bool p);

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector <edge> all(m + 1);
	all[0] = {0, 0, inf};
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		all[i] = e[i];
	}

	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	sort(all.begin(), all.end());
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		ans[i] = true;
		int k;
		scanf("%d", &k);
		// vector <edge> v(k);
		for (int j = 0; j < k; ++j) {
			int en;
			scanf("%d", &en);
			mp[{e[en].w, i}].pb(en);
		}
	}

	// cerr << "kdjf" << endl;
	auto mp_it = mp.begin();
	int nxt_w = all[0].w;
	for (int i = 0; i < m; ++i) {
		while (mp_it != mp.end()) {
			// auto p = *mp_it;
			if (mp_it->first.first <= nxt_w) {
				// cerr << "qry " << p.first.first << ' ' << p.first.second << endl;
				for (auto &ed : mp_it->second) {
					// cerr << e[ed].u << ' ' << e[ed].v << endl;
					if (dsu_check(e[ed].u, e[ed].v, true)) {
						ans[mp_it->first.second] = false;
						break;
					} else {
						dsu_join(e[ed].u, e[ed].v, true);
					}
				}
				// cerr << "reset" << endl;
				dsu_reset();
				++mp_it;
			} else {
				break;
			}
		}
		// cerr << "join " << all[i].u << ' ' << all[i].v << endl;
		dsu_join(all[i].u, all[i].v, false);
		nxt_w = all[i + 1].w;
	}

	for (int i = 1; i <= q; ++i) {
		if (ans[i]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}

void dsu_join(int i, int j, bool p) {
	int u = dsu_find(i, p), v = dsu_find(j, p);
	if (u != v) {
		if (get_depth(u, p) < get_depth(v, p)) {
			dsu_set(u, v, p);
			set_depth(v, max(get_depth(v, p), get_depth(u, p)), p);
		} else {
			dsu_set(v, u, p);
			set_depth(u, max(get_depth(u, p), get_depth(v, p)), p);
		}
	}
}

int dsu_find(int i, bool p) {
	if (i == dsu_get(i, p)) {
		return i;
	} else {
		int root = dsu_find(dsu_get(i, p), p);
		dsu_set(i, root, p);
		return root;
	}
}

bool dsu_check(int i, int j, bool p) {
	return dsu_find(i, p) == dsu_find(j, p);
}

int dsu_get(int i, bool p) {
	if (!p or !upd[i]) {
		return parent[i];
	} else {
		return temp[i];
	}
}

void dsu_set(int i, int j, bool p) {
	if (!p) {
		parent[i] = j;
	} else {
		temp[i] = j;
		if (!upd[i]) {
			upd[i] = true;
			st.push(i);
		}
	}
}

void dsu_reset() {
	while (!st.empty()) {
		upd[st.top()] = false;
		st.pop();
	}
	while (!st_depth.empty()) {
		upd_depth[st_depth.top()] = false;
		st_depth.pop();
	}
}

int get_depth(int i, bool p) {
	if (!p or !upd_depth[i]) {
		return depth[i];
	} else {
		return temp_depth[i];
	}
}

void set_depth(int i, int j, bool p) {
	if (!p) {
		depth[i] = j;
	} else {
		temp_depth[i] = j;
		if (!upd_depth[i]) {
			upd_depth[i] = true;
			st_depth.push(i);
		}
	}
}