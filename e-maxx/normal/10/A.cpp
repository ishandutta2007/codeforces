#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int MAXT = 2000;

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	vector<char> u (MAXT);
	int lt, rt;
	for (int i=0; i<n; ++i) {
		int l, r;
		cin >> l >> r;
		for (int j=l; j<=r-1; ++j)
			u[j] = true;
		if (i == 0)
			lt = l;
		if (i == n-1)
			rt = r-1;
	}

	int ans = 0,  last = 0;
	for (int i=0; i<=rt; ++i) {
		if (u[i])
			last = i;

		int cur;
		if (i-last <= t1)
			cur = p1;
		else if (i-last-t1 <= t2)
			cur = p2;
		else
			cur = p3;

		if (i >= lt)
			ans += cur;
	}
	cout << ans;

}