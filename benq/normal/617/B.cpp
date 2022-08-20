#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> indices;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 1) indices.push_back(i);
	}
	if (indices.size() == 0) {
		cout << 0;
	} else if (indices.size() == 1) {
		cout << 1;
	} else {
		long long ans = 1;
		for (int i = 0; i < indices.size()-1; ++i) {
			ans *= (indices[i+1]-indices[i]);
		}
		cout << ans;
	}
	return 0;
}