#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int n;

int get (int x, int y) {
	if (x == 0)  return y;
	if (y == n)  return n + x;
	if (x == n)  return 2*n + (n-y);
	if (y == 0)  return 3*n + (n-x);
	throw;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	int a = get (x1, y1),
		b = get (x2, y2);
	int ans = min (abs (a - b),
		min (4*n - a + b, 4*n - b + a));
	cout << ans;

}