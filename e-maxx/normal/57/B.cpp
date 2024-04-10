#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


struct item {
	int l, r, h;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, m, k;
	cin >> n >> m >> k;
	vector<item> e (m);
	for (int i=0; i<m; ++i)
		scanf ("%d%d%d", &e[i].l, &e[i].r, &e[i].h);

	long long ans = 0;
	for (int i=0; i<k; ++i) {
		int x;
		cin >> x;
		
		for (int i=0; i<m; ++i)
			if (e[i].l <= x && x <= e[i].r)
				ans += e[i].h + (x - e[i].l);
	}
	cout << ans;

}