#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, d;
	cin >> n >> d;
	int prev;
	int ans = 0;
	for (int i=0; i<n; ++i) {
		int cur;
		cin >> cur;
		if (i)
			if (cur <= prev) {
				int add = (prev+1 - cur + d - 1) / d;
				cur += d * add;
				ans += add;
			}
		prev = cur;
	}

	cout << ans;

}