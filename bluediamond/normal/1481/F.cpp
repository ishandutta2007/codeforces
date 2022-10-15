#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;
const int N = (int)1e5 + 7;
int n, x, p[N], dep[N], maxdep, cnt_on_dep[N], times[N], last[N], times_last[N];
bool ok[N];
int color[N];
vector<int> g[N];
vector<int> someone_having[N];
vector<int> guys_on_dep[N];

void build(int a) {
	guys_on_dep[dep[a]].push_back(a);
	cnt_on_dep[dep[a]]++;
	for (auto& b : g[a]) {
		dep[b] = 1 + dep[a];
		build(b);
	}
}

int main() {
#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(0); cin.tie(0);
#endif 

	cin >> n >> x;
	x = n - x;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	build(1);
	maxdep = *max_element(dep + 1, dep + n + 1);
	
	{
		// try maxdep + 1
		for (int d = 0; d <= maxdep; d++) {
			times[cnt_on_dep[d]]++;
			someone_having[cnt_on_dep[d]].push_back(d);
		}
		ok[0] = 1;
		for (int x = 1; x <= n; x++) {
			if (times[x] == 0) continue;
			for (int i = x; i <= n; i++) {
				if (ok[i]) continue;
				if (ok[i - x] && (last[i - x] != x || times_last[i - x] + 1 <= times[x])) {
					ok[i] = 1;
					last[i] = x;
					times_last[i] = ((last[i - x] != x) ? (1) : (times_last[i - x] + 1));
				}
			}
		}
		assert(ok[x] == ok[n - x]);
		if (ok[x]) {
		
			vector<int> what;
			while (x) {
				what.push_back(last[x]);
				x -= last[x];
			}
			for (auto& sz : what) {
				assert(!someone_having[sz].empty());
				int d = someone_having[sz].back();
				someone_having[sz].pop_back();
				for (auto& v : guys_on_dep[d]) {
					color[v] = 1;
				}
			}
			cout << maxdep + 1 << "\n";
			for (int i = 1; i <= n; i++) {
				cout << (char)('a' + color[i]);
			}
			cout << "\n";
			exit(0);
		}
	}
	//cout << "bad, but the answer is " << maxdep + 2 << "\n";


	int verts_left = n;
	for (int d = 0; d <= maxdep; d++) {
		if (cnt_on_dep[d] <= x) {
			x -= cnt_on_dep[d];
			verts_left -= cnt_on_dep[d];
			for (auto& v : guys_on_dep[d]) {
				color[v] = 1;
			}
			continue;
		}
		if (cnt_on_dep[d] <= verts_left - x) {
			verts_left -= cnt_on_dep[d];
			continue;
		}
		assert(verts_left + 1 - cnt_on_dep[d] <= x);
		assert(x <= cnt_on_dep[d]);

		vector<int> v_leafs, v_non_leafs;
		int leafs = 0, non_leafs = 0;
		for (auto& v : guys_on_dep[d]) {
			leafs += g[v].empty();
			non_leafs += !g[v].empty();
			if (g[v].empty()) {
				v_leafs.push_back(v);
			}
			else {
				v_non_leafs.push_back(v);
			}
		}

		if (non_leafs <= x) {
			for (auto& v : v_non_leafs) {
				color[v] = 1;
				x--;
			}
			assert(x >= 1);
			for (auto& v : v_leafs) {
				if (x == 0) break;
				color[v] = 1;
				x--;
			}
			assert(x == 0);
		}
		else {
			assert(non_leafs <= verts_left - x);
			x = verts_left - x;
			for (auto& v : v_non_leafs) {
				color[v] = 1;
				x--;
			}
			assert(x >= 1);
			for (auto& v : v_leafs) {
				if (x == 0) break;
				color[v] = 1;
				x--;
			}
			assert(x == 0);
			for (int j = d; j <= maxdep; j++) {
				for (auto& v : guys_on_dep[j]) {
					color[v] ^= 1;
				}
			}
		}
		break;

		/*
		cnt_on_dep[d] >= x + 1
		cnt_on_dep[d] >= verts_left - x + 1

		cnt_on_dep[d] - 1 >= x >= verts_left + 1 - cnt_on_dep[d]
		verts_left + 1 - cnt_on_dep[d] <= x <= cnt_on_dep[d]

		non_leafs * 2 <= verts_left => 
		non_leafs <= verts_left / 2 <= max(x, verts_lefts - x)

		// I can consume everything I want here
		*/
		

	}

	cout << maxdep + 2 << "\n";
	for (int i = 1; i <= n; i++) {
		cout << (char)('a' + color[i]);
	}
	cout << "\n";
	exit(0);
}