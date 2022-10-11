#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[100009][4]; vector<pair<int, int>>vec;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) cin >> a[i][j];
		vec.push_back(make_pair(-a[i][0] - a[i][1] - a[i][2] - a[i][3], i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (vec[i].second == 0) { cout << i + 1 << endl; break; }
	}
	return 0;
}