#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<bool> > v;

void pfx(vector<bool>& a, vector<bool>& b) {
	int sz = 0;
	for (int i = 0; i < a.size() && i < b.size(); ++i) {
		if (a[i] == b[i])
			++sz;
		else
			break;
	}
	while (a.size() > sz)
		a.pop_back();
}

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		vector<bool> s;
		int k;
		cin >> k;
		while (k > 0) {
			s.push_back(k % 2);
			k /= 2;
		}
		reverse(s.begin(), s.end());
		v.push_back(s);
	}

	int ops = 0;

	vector<bool> p = v[0];
	for (int i = 1; i < n; ++i)
		pfx(p, v[i]);

	int median = 0;
	vector<int> res;

	for (int i = 0; i < n; ++i) {
		//highest one bit not in prefox
		int j = 0;
		for (int k = p.size(); k <= v[i].size(); ++k) {
			if (v[i][k] == 1) {
				j = v[i].size() - k;
				break;
			}
		}
		ops += j;
		res.push_back(v[i].size() - p.size() - j);
	}
	sort(res.begin(), res.end());
	median = res[res.size() / 2];
	for (int i = 0; i < n; ++i) {
		ops += abs(median - res[i]);
	}
	cout << ops << "\n";
	return 0;
}