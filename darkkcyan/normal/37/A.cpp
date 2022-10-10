#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int c = 1, cc = 1, mc = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) cc++;
		else {
			++c;
			mc = max(mc, cc);
			cc = 1;
		}
	}
	mc = max(mc, cc);
	cout << mc << ' ' << c;
	return 0;
}