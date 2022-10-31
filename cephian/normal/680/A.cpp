#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[5];
	int sm = 0;
	for(int i = 0; i < 5; ++i) {
		cin >> a[i];
		sm += a[i];
	}
	int best = 0;
	for(int t = 1; t <= 100; ++t) {
		int m = 0;
		for(int i = 0; i < 5; ++i)
			m += a[i] == t;
		if(m >= 2) {
			best = max(best, min(3,m) * t);
		}
	}
	cout << sm-best << "\n";
}