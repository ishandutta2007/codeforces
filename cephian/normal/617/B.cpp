#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if(k) v.push_back(i);
	}
	if(v.size() == 0) {
		cout  << "0\n";
		return 0;
	}
	ll ans = 1;
	for(int i = 1; i < v.size(); ++i) {
		ans *= v[i] - v[i-1];
	}
	cout << ans << "\n";
}