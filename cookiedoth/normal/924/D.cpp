/*
,##.                   ,==.
,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ;
`#    #'                 /   .'
`##'                   "=="
*/

#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("Ofast")
#define ld long double

using namespace std;

const int null = 0;
const ld eps = 1e-6;

struct fenwick {

	vector<int> t;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void update(int pos) {
		while (pos < n) {
			t[pos] += 1;
			pos = pos | (pos + 1);
		}
	}

	int get(int r) {
		int res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) {
		if (l > r)
			return 0;
		return get(r) - get(l - 1);
	}

};

fenwick f;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	ld w;
	cin >> n >> w;
	w += eps;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<pair<ld, ld> > t1(n);
	for (int i = 0; i < n; i++) {
		t1[i] = { (ld)a[i].first / ((ld)a[i].second - w), (ld)a[i].first / ((ld)a[i].second + w) };
	}
	sort(t1.begin(), t1.end());
	vector<ld> all;
	for (int i = 0; i < n; i++) {
		all.push_back(t1[i].second);
	}
	sort(all.begin(), all.end());
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = lower_bound(all.begin(), all.end(), t1[i].second) - all.begin();
	}
	f.init(n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		f.update(p[i]);
		ans += f.get(p[i] + 1, n - 1);
	}
	cout << ans << endl;
	return 0;
}