#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	multiset<int> b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		b.insert(x);
	}
	
	for (int i = 0; i < n; ++i) {
		auto it = b.lower_bound(n - a[i]);
		if (it == b.end()) it = b.begin();
		cout << (a[i] + *it) % n << " ";
		b.erase(it);
	}
	cout << endl;
	
	return 0;
}