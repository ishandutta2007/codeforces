#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

#define internal INTERNAL

const int N = 1000;
const int DEBUG = 0;

int n;
bool internal[N];
bitset<N> s[N], adj[N];
vector<int> vs[N];
set<pair<int, int> > edges;
int attach[N];

void add_edge(int a, int b) {
	if (b > a) swap(a, b);
	edges.insert(make_pair(a, b));
	if (DEBUG) printf("add edge %d %d\n", a, b);
}

void solve() {
	{
		//star
		int tot = 0;
		for (auto &v : vs) tot += v.size();
		if (tot == n * n) {
			for (int i = 1; i < n; i++) {
				edges.insert(make_pair(0, i));
			}
			return ;
		}
	}
	fill(internal, internal + n, false);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			static bitset<N> t;
			t = s[i] & s[j];
			if (t.count() == 2) {
				static vector<int> v;
				v.clear();
				for (int k = 0; k < n; k++) {
					if (t[k]) v.push_back(k);
				}
				internal[v[0]] = true;
				internal[v[1]] = true;
				add_edge(v[0], v[1]);
				adj[v[1]][v[0]] = adj[v[0]][v[1]] = 1;
				internal[v[0]] = internal[v[1]] = 1;
			}
		}
	}

	if (DEBUG) cerr << "internal edge over" << endl;

	for (int i = 0; i < n; i++) if (!internal[i]) {
		int c = -1;
		for (int j = 0; j < n; j++) {
			if (s[j][i] && (c == -1 || vs[j].size() < vs[c].size())) {
				c = j;
			}
		}
		vector<int> sub;
		bitset<N> mask;
		for (int j = 0; j < vs[c].size(); j++) {
			int y = vs[c][j];
			if (internal[y]) {
				sub.push_back(y);
				mask[y] = 1;
			}
		}
		if (sub.size() > 2) {
			for (auto v : sub) {
				if ((adj[v] & mask).count() > 1) {
					add_edge(v, i);
					break;
				}
			}
			continue;
		}
		assert(sub.size() == 2);
		int a = sub[0], b = sub[1];
		if (adj[b].count() > 1) swap(a, b);
		if (adj[a].count() > 1) {
			add_edge(b, i);
			continue;
		}

		// dumbbell
		if (DEBUG) cerr << "dumbbell" << endl;
		int choose = a;
		for (int j = 0; j < i; j++) if (!internal[j]) {
			if (s[c][j] == 0 && attach[j] == a) {
				choose = b;
				break;
			}
			if (s[c][j]) {
				choose = attach[j];
				break;
			}
		}
		add_edge(choose, i);
		attach[i] = choose;
	}
	return ;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int x; scanf("%d", &x);
			vs[i].push_back(--x);
			s[i][x] = 1;
		}
	}
	solve();
	for (auto v : edges) {
		printf("%d %d\n", v.first + 1, v.second + 1);
	}
	return 0;
}