#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


int x, y, z, k;

bool read() {
	return !! (cin >> x >> y >> z >> k);
}


long long solve (int x, int y, int z, int k) {
	int cx=0, cy=0, cz=0;
	while (k) {
		int kk = k;
		if (cx+1 < x && k)
			++cx, --k;
		if (cy+1 < y && k)
			++cy, --k;
		if (cz+1 < z && k)
			++cz, --k;
		if (k == kk)  break;
	}
	return (1ll + cx) * (1 + cy) * (1 + cz);
}

void solve() {
	cout << solve (x, y, z, k) << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}