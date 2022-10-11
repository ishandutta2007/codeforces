#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a[200009], s[200009]; vector<pair<int, int>>x[1000009]; vector<int> y[1000009];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); s[i] = i - x[a[i]].size();
		x[a[i]].push_back(make_pair(i - x[a[i]].size(), i));
		y[a[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		int l, r, p; scanf("%d%d%d", &l, &r, &p);
		if (x[p].size() == 0) { cout << l << endl; continue; }
		int pos = lower_bound(y[p].begin(), y[p].end(), l) - y[p].begin();
		if (y[p].size() == pos || y[p][pos] != l) { cout << l << endl; continue; }

		pos = y[p][pos];
		int pos1 = lower_bound(x[p].begin(), x[p].end(), make_pair(s[pos] + 1, -100000000)) - x[p].begin(); pos1--;
		if (pos1 < 0) { cout << l << endl; continue; }
		else {
			int Z = x[p][pos1].second + 1;
			if (Z > r) { cout << "-1" << endl; }
			else { cout << Z << endl; }
		}
	}
	return 0;
}