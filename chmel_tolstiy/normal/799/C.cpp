#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int f(int c, vector<pii> x) {
	set<pii> other;
	sort(x.begin(), x.end());

	int res = 0;
	for (int i = 0; i < x.size(); ++i) {
		while (other.size() && other.rbegin()->second + x[i].first > c) other.erase(--other.end());
		if (other.size()) res = max(res, x[i].second + other.rbegin()->first);
		other.insert(pii(x[i].second, x[i].first));
	}
	return res;
}

bool solve() {
	int n, c, d;
	scanf("%d%d%d", &n, &c, &d);
	vector<pii> cc, dd;
	for (int i = 0; i < n; ++i) {
		int b, p;
		static char T[10];
		scanf("%d %d %s", &b, &p, T);
		if (T[0] == 'C') cc.push_back(pii(p, b));
		else dd.push_back(pii(p, b));
	}

	int res = 0;
	int bc = 0, bd = 0;
	for (int i = 0; i < cc.size(); ++i) if (cc[i].first <= c) {
		bc = max(bc, cc[i].second);
	}
	for (int i = 0; i < dd.size(); ++i) if (dd[i].first <= d) {
		bd = max(bd, dd[i].second);
	}

	res = max(res, f(c, cc));
	res = max(res, f(d, dd));

	if (bc > 0 && bd > 0)
		res = max(res, bc + bd);

	cout << res << endl;
		
	return false;
}

int main() {
	
    while (solve());
    
    return 0;
}