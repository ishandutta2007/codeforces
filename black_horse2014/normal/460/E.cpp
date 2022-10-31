#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using pii = pair<int, int>;

int value, sz;
vector<pair<int, int>> vec, good;

vector<int> ids;

void dfs(int k, int u) {
	if (k == 0) {
		vector<pair<int, int>> pts;
		for (int j : ids) {
			pts.push_back(vec[j]);
		}
		int sum = 0;
		for (int j = 0; j < pts.size(); j++) {
			for (int k = j+1; k < pts.size(); k++) {
				sum += (pts[j].x-pts[k].x) * (pts[j].x-pts[k].x) + (pts[j].y-pts[k].y) * (pts[j].y-pts[k].y);
			}
		}
		if (value < sum) {
			value = sum;
			good = pts;
		}
		return;
	}
	for (int i = u; i < sz; i++) {
		ids.push_back(i);
		dfs(k-1, i);
		ids.pop_back();
	}
}

int main() {
	int n, r; cin >> n >> r;
	if (n % 2 == 0) {
		cout << r * r * n * n << endl;
		for (int i = 0; i < n; i++) {
			if (i & 1) cout << 0 << ' ' << r << endl;
			else cout << 0 << ' ' << -r << endl;
		}
		return 0;
	}
	for (int i = -r; i <= r; i++) {
		int j = (int)floor(sqrt(r * r - i * i));
		vec.emplace_back(i, j);
		if (abs(i) < r) vec.emplace_back(i, -j);
	}
	random_shuffle(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(), [](pii a, pii b) {
		return a.x*a.x+a.y*a.y > b.x*b.x+b.y*b.y;
	});
	sz = min(18, (int)vec.size());
	dfs(n, 0);
	cout << value << endl;
	for (auto t : good) {
		cout << t.x << ' ' << t.y << endl; 
	}
}