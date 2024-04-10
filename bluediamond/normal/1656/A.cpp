#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		cout << min_element(a.begin(), a.end()) - a.begin() + 1 << " " << max_element(a.begin(), a.end()) - a.begin() + 1 << "\n";
	}
}