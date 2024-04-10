#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[100009], maxn = 0, minid = 100000, minx = -1; vector<pair<int, int>>vec; bool flag[100009];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		if (maxn < a[i]) { vec.push_back(make_pair(a[i], i)); maxn = a[i]; flag[i] = true; }
		else { minx = 0; minid = min(minid, a[i]); }
	}
	for (int i = 0; i < vec.size(); i++) {
		int L = vec[i].second + 1, R = n; if (i != vec.size() - 1) R = vec[i + 1].second - 1;

		int J = 0, sum = 0; if (i >= 1) J = vec[i - 1].first;
		for (int j = L; j <= R; j++) {
			if (J < a[j]) { J = a[j]; sum++; }
		}
		sum--;
		if (sum > minx) {
			minx = sum; minid = vec[i].first;
		}
		if (sum == minx) {
			minid = min(minid, vec[i].first);
		}
	}
	cout << minid << endl;
	return 0;
}