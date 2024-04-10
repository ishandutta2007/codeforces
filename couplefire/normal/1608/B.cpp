#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	if (abs(a - b) > 1) return puts("-1"), void();
	if (a + b > n) return puts("-1"), void();

	vector<int> vec;
	for (int i = 1, j = n, k = 1; k <= a + b; k++) {
		if (k & 1) vec.push_back(i++);
		else vec.push_back(j--);
	}

	if (a == b) {
		if (n - a - b < 2) return puts("-1"), void();
		int nw = n - a;
		vec.insert(vec.begin(), nw--);
		while (nw > b) vec.push_back(nw--);
	}
	else if (a == b - 1) {
		if (n - a - b < 2) return puts("-1"), void();
		int nw = b + 1;
		vec.insert(vec.begin(), nw++);
		while (nw < n - a + 1) vec.push_back(nw++);
	}
	else if (b == a - 1) {
		vec.clear();
		for (int i = 1, j = n, k = 1; k <= a + b; k++) {
			if (k & 1) vec.push_back(j--);
			else vec.push_back(i++);
		}
		if (n - a - b < 2) return puts("-1"), void();
		int nw = n - a;
		vec.insert(vec.begin(), nw--);
		while (nw > b) vec.push_back(nw--);	
	}
	for (int x: vec) cout << x << " ";
	cout << endl;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
}