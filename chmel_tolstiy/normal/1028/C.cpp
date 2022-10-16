#pragma comment(linker, "/STACK:512000111")
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cassert>

using namespace std; 


void solve() {
	int n; cin >> n;
	
	vector<int> xl(n + 1), xr(n + 1), yl(n + 1), yr(n + 1);
	for (int i = 1; i <= n; ++i) cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
	const int INF = 1 << 30;

	vector<int> xll(n + 2, -INF), xlr(n + 2, -INF);
	vector<int> xrl(n + 2, +INF), xrr(n + 2, +INF);
	vector<int> yll(n + 2, -INF), ylr(n + 2, -INF);
	vector<int> yrl(n + 2, +INF), yrr(n + 2, +INF);

	for (int i = 1; i <= n; ++i) {
		xll[i] = max(xll[i-1], xl[i]);
		xrl[i] = min(xrl[i-1], xr[i]);
		yll[i] = max(yll[i-1], yl[i]);
		yrl[i] = min(yrl[i-1], yr[i]);
	}

	for (int i = n; i >= 1; --i) {
		xlr[i] = max(xlr[i+1], xl[i]);
		xrr[i] = min(xrr[i+1], xr[i]);
		ylr[i] = max(ylr[i+1], yl[i]);
		yrr[i] = min(yrr[i+1], yr[i]);	
	}

	for (int i = 1; i <= n; ++i) {
		int X1 = max(xll[i - 1], xlr[i + 1]);
		int X2 = min(xrl[i - 1], xrr[i + 1]);
		int Y1 = max(yll[i - 1], ylr[i + 1]);
		int Y2 = min(yrl[i - 1], yrr[i + 1]);

		if (X1 <= X2 && Y1 <= Y2) {
			cout << X1 << ' ' << Y1 << endl;
			return;
		}
	}

	assert(false);
}

int main() {
	int t; //cin >> t;
    t = 1;
	while (t-->0) solve();
	return 0;
}