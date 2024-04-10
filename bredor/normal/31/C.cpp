//  228

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, x, y, last;
	cin >> n;
	vector<tuple<int, int, int>> a(n);
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		a[i] = { x, y, i };
	}
	sort(a.begin(), a.end());
	
	vector<int> ans;
	for (i = 0; i < n; i++) {
		last = -1;
		bool valid = true;
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			if (get<0>(a[j]) < last) {
				valid = false;
				break;
			}
			last = get<1>(a[j]);
		}
		if (valid) ans.push_back(get<2>(a[i]));
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto p : ans) cout << p + 1 << " ";
	cout << "\n";

	return 0;
}