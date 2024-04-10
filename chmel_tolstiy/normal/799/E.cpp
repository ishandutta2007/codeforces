#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<long long, long long> pii;
typedef vector<int> vi;
typedef vector<pii> vp;


bool solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<pii> c(n); 
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i].first);
		c[i].second = i;
	}
	sort(c.begin(), c.end());

	int X; scanf("%d", &X);
	vector<int> xx(n); for (int i = 0; i < X; ++i) {
		int z; scanf("%d", &z); --z;
		xx[z] = 1;
	}
	int Y; scanf("%d", &Y); 
	vector<int> yy(n); for (int i = 0; i < Y; ++i) {
		int z; scanf("%d", &z);--z;
		yy[z] = 1;
	}

	long long res = -1;

	long long as, xs, ys, us;
	as = xs = ys = us = 0;
	multiset<pii> all, sx, sy, free, used;

	for (int i = 0; i < n; ++i) {
		int id = c[i].second;
		if (xx[id] && yy[id]) { all.insert(c[i]); continue; }
		if (xx[id]) { 
			sx.insert(c[i]);
			xs += c[i].first;
			continue;
		}
		if (yy[id]) { 
			sy.insert(c[i]);
			ys += c[i].first;
			continue;
		}
		free.insert(c[i]);
	}

	int call = all.size();

	for (int both = 0; both <= call && both <= m; ++both) {
		
		int _b = min(both, k);

		while (_b + sx.size() > k && sx.size()) {
			pii z = *sx.rbegin(); sx.erase(--sx.end());
			xs -= z.first;
			free.insert(z);
		}
		while (_b + sy.size() > k && sy.size()) {
			pii z = *sy.rbegin(); sy.erase(--sy.end());
			ys -= z.first;
			free.insert(z);
		}

		if (_b + sx.size() + sy.size() <= m && sx.size() == k - _b && sy.size() == k - _b) {

			while (used.size() < m - _b - sx.size() - sy.size() && free.size()) {
				pii z = *free.begin();
				free.erase(free.begin());
				us += z.first;
				used.insert(z);
			}

			while (used.size() && free.size() && used.rbegin()->first > free.begin()->first) {
				pii z = *used.rbegin(); used.erase(--used.end());
				pii w = *free.begin(); free.erase(free.begin());
				used.insert(w);
				free.insert(z);
				us -= z.first;
				us += w.first;
			}

			if (used.size() + _b + sx.size() + sy.size() == m) {
				if (res < 0) res = 1LL << 60;
				res = min(res, as + xs + ys + us);
			}
		}

		if (all.size() == 0) break;
		
		if (both < k) {
			as += all.begin()->first;
		} else {
			free.insert(*all.begin());
		}
		all.erase(all.begin());
	}

	cout << res << endl;

	return false;
}

int main() {
	
    while (solve());
    
    return 0;
}