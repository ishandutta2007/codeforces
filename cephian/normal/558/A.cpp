#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int arr[100];

vector<pair<int, int> > v;

int go(int init, int dir) {
	int i = init;
	int ans = 0;
	for (int add = 1; i < v.size() && i >= 0; ++add) {
		ans += arr[i];
		i = i + add * dir;
		dir *= -1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, a;
		cin >> x >> a;
		v.push_back(make_pair(x, a));
	}
	v.push_back(make_pair(0, 0));
	sort(v.begin(), v.end());

	int init = -1;
	for (int i = 0; i < n + 1; ++i) {
		arr[i] = v[i].second;
		if (v[i].first == 0)
			init = i;
	}

	cout << max(go(init, 1), go(init, -1)) << "\n";

	return 0;
}