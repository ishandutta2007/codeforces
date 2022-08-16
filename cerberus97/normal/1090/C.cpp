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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct child {
	int ctr, idx;
	bool operator<(const child &o) const {
		return ctr < o.ctr;
	}
};

struct S {
	int from, to, type;
};

child c[N];
set<int> a[N];
vector<S> ans;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	int total = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i].ctr;
		c[i].idx = i;
		total += c[i].ctr;
		for (int j = 0; j < c[i].ctr; ++j) {
			int x; cin >> x;
			a[i].insert(x);
		}
	}
	sort(c + 1, c + 1 + n);
	int hi_ctr = total % n; 
	int i = 1, j = n;
	while (i < j) {
		int lo, hi;
		if (i >= n - hi_ctr + 1) {
			lo = total / n + 1;
		} else {
			lo = total / n;
		}
		if (j >= n - hi_ctr + 1) {
			hi = total / n + 1;
		} else {
			hi = total / n;
		}
		int transfer = min(lo - c[i].ctr, c[j].ctr - hi);
		int idx1 = c[i].idx, idx2 = c[j].idx;
		// cout << idx1 << ' ' << idx2 << ' ' << transfer << endl;
		vector<int> found;
		auto it1 = a[idx1].begin(), it2 = a[idx2].begin();
		while (transfer) {
			if (it1 == a[idx1].end()) {
				found.pb(*it2);
				++it2;
				--transfer;
			} else if (*it1 == *it2) {
				++it1;
				++it2;
			} else if (*it1 < *it2) {
				++it1;
			} else {
				found.pb(*it2);
				++it2;
				--transfer;
			}
		}
		for (auto &f : found) {
			ans.pb({idx2, idx1, f});
			a[idx2].erase(f);
			a[idx1].insert(f);
		}
		c[i].ctr += found.size();
		c[j].ctr -= found.size();
		if (c[i].ctr >= lo) {
			++i;
		}
		if (c[j].ctr == hi) {
			--j;
		}
	}
	cout << ans.size() << '\n';
	for (auto &f : ans) {
		cout << f.from << ' ' << f.to << ' ' << f.type << '\n';
	}
}