#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n] = {0};
	for (int i = 0; i < n; ++i) {
		for (int f = 0; f < n; ++f) {
			int x; cin >> x;
			if (x == -1) continue;
			a[i] += x bitand 1;
		}
		a[i] = (a[i] ? 0 : i + 1);
	}
	
	auto t = remove_if(a, a + n, logical_not<int>());
	
	cout << (t - a) << endl;
	for (auto i = a; i != t; ++i) {
		cout << *i << ' ' ;
	}
	return 0;
}