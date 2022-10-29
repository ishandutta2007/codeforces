#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, m, k;
	cin >> n >> m >> k;

	bool ans = false;
	for (int i=0; i<k; ++i) {
		int x, y;
		cin >> x >> y;

		if (n <= 4 || m <= 4)
			ans = true;
		else if (x <= 5 || x >= n-4 || y <= 5 || y >= m-4)
			ans = true;
	}

	puts (ans ? "YES" : "NO");

}