/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct interv {
	int l, r, id;
	bool operator<(const interv& o) const {
		return tie(l, r) < tie(o.l, o.r);
	}
};

void pans(vector<int>& p, vector<interv>& a);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<interv> a(n);
	int nxt = 1;
	for (auto& i : a) {
		cin >> i.l >> i.r;
		i.id = nxt++;
	}
	sort(a.begin(), a.end());
	set<pii> cur;
	int j = 0;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) {
		while (j < n and a[j].l <= i) {
			cur.insert({a[j].r, j});
			++j;
		}
		p[i] = (*cur.begin()).second;
		cur.erase(cur.begin());
	}
	vector<vector<int>> at(n + 1);
	for (int i = n; i >= 1; --i) {
		int l = a[p[i]].l;
		if (l < i) {
			at[l].pb(i);
		}
	}
	set<int> active;
	for (int i = 1; i <= n; ++i) {
		for (auto& x : at[i]) {
			active.insert(x);
		}
		while (!active.empty() and *active.begin() <= i) {
			active.erase(active.begin());
		}
		if (!active.empty() and *active.begin() <= a[p[i]].r) {
			j = *active.begin();
			auto q = p;
			swap(q[i], q[j]);
			cout << "NO\n";
			pans(p, a);
			pans(q, a);
			return 0;
		}
	}
	cout << "YES\n";
	pans(p, a);
}

void pans(vector<int>& p, vector<interv>& a) {
	int n = a.size();
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; ++i) {
		ans[a[p[i]].id] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}