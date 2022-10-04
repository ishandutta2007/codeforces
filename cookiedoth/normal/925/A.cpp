#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define int long long

using namespace std;

const int INF = 1000000000000000000;

int n, m, c1, c2, v;

int cnt(int x1, int x2, int y1, int y2, int y, int v) {
	return abs(y1 - y) + abs(y2 - y) + (abs(x1 - x2) + v - 1) / v;
}

bool corr(int ind, int sz) {
	return ind >= 0 && ind < sz;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> c1 >> c2 >> v;
	vector<int> t1(c1), t2(c2);
	for (int i = 0; i < c1; i++) {
		cin >> t1[i];
		t1[i]--;
	}
	for (int i = 0; i < c2; i++) {
		cin >> t2[i];
		t2[i]--;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		if (x1 == x2) {
			cout << abs(y2 - y1) << '\n';
		}
		else {
			int ind1 = lower_bound(t1.begin(), t1.end(), y1) - t1.begin();
			int ind2 = ind1 - 1;
			int ind3 = lower_bound(t1.begin(), t1.end(), y2) - t1.begin();
			int ind4 = ind3 - 1;
			//cout << ind1 << ' ' << ind2 << ' ' << ind3 << ' ' << ind4 << endl;
			int var = INF;
			if (corr(ind1, c1)) var = min(var, cnt(x1, x2, y1, y2, t1[ind1], 1));
			if (corr(ind2, c1)) var = min(var, cnt(x1, x2, y1, y2, t1[ind2], 1));
			if (corr(ind3, c1)) var = min(var, cnt(x1, x2, y1, y2, t1[ind3], 1));
			if (corr(ind4, c1)) var = min(var, cnt(x1, x2, y1, y2, t1[ind4], 1));
			int ind5 = lower_bound(t2.begin(), t2.end(), y1) - t2.begin();
			int ind6 = ind5 - 1;
			int ind7 = lower_bound(t2.begin(), t2.end(), y2) - t2.begin();
			int ind8 = ind7 - 1;
			if (corr(ind5, c2)) var = min(var, cnt(x1, x2, y1, y2, t2[ind5], v));
			if (corr(ind6, c2)) var = min(var, cnt(x1, x2, y1, y2, t2[ind6], v));
			if (corr(ind7, c2)) var = min(var, cnt(x1, x2, y1, y2, t2[ind7], v));
			if (corr(ind8, c2)) var = min(var, cnt(x1, x2, y1, y2, t2[ind8], v));
			cout << var << '\n';
		}
	}
	return 0;
}