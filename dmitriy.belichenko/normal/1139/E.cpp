// kuhn by CLONE3
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <iomanip>
#include <ctime>
using namespace std;

#define ll long long
#define ld long double

using namespace std;

const int N = 5100;
const int MOD = 1e9 + 7;

int c[N];
int p[N];

map <int, int> g[N];
int pr[N];
int pl[N];
bool was[N];

bool try_kuhn(int v) {
	if (was[v]) return false;
	was[v] = true;
	for (auto lr : g[v]) {
		if (lr.second <= 0) continue;
		int x = lr.first;
		if (pr[x] == -1) {
			pr[x] = v;
			pl[v] = x;
			return true;
		}
	}
	for (auto lr : g[v]) {
		if (lr.second <= 0)
			continue;
		int x = lr.first;
		if (try_kuhn(pr[x])) {
			pr[x] = v;
			pl[v] = x;
			return true;
		}
	}
	return false;
}

bool try_kuhn2(int v, int border) {
	if (was[v]) return false;
	was[v] = true;
	for (auto lr : g[v]) {
		int x = lr.first;
		if (pr[x] == -1) {
			pr[x] = v;
			pl[v] = x;
			return true;
		}
	}
	for (auto lr : g[v]) {
		int x = lr.first;
		int paired = pr[x];
		if (paired > border) {
			pr[x] = v;
			pl[v] = x;
			pl[paired] = -1;
			return true;
		}

		if (try_kuhn2(pr[x], border)) {
			pr[x] = v;
			pl[v] = x;
			return true;
		}
	}
	return false;

}

int main() {
	::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	set <int> ps;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		ps.insert(p[i]);
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		g[p[i]][c[i]]++;
	}
	int i = 0;
	memset(pl, -1, sizeof(pl));
	memset(pr, -1, sizeof(pr));
	for (i = 0; i < n; ++i) {
		memset(was, 0, sizeof(was));
		if (!try_kuhn(i)) {
			break;
		}
	}
	int d;
	cin >> d;
	while (d--) {
		int x;
		cin >> x;
		--x;
		int r = p[x];
		if (--g[p[x]][c[x]] == 0) {
			g[p[x]].erase(c[x]);
		}
		if (i >= r && pl[r] != -1) {
			int v = pl[r];
			pl[r] = -1;
			pr[v] = -1;
			memset(was, 0, sizeof(was));
			if (!try_kuhn(r)) {
				for (int tryhard = r; tryhard <= n; ++tryhard) {
					if (pl[tryhard] != -1)
						continue;
					memset(was, 0, sizeof(was));
					if (!try_kuhn2(tryhard, tryhard)) {
						i = tryhard;
						break;
					}
				}
			}
		}
		cout << i << "\n";
		//cout << "> " << i << "\n";
	}
	return 0;
}