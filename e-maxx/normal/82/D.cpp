#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int INF = 1000000100;
const int MAXN = 1100;


int n, a[MAXN];

bool read() {
	if (! (cin >> n))  return false;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	return true;
}


int d[MAXN][MAXN];

int get_d (int fs, int sc) {
	if (sc == n)  return a[fs];
	if (sc == n-1)  return max(a[fs],a[sc]);

	int & my = d[fs][sc];
	if (my != -1)  return my;
	my = INF;

	my = min (my, max(a[fs],a[sc]) + get_d (sc+1, sc+2));
	my = min (my, max(a[fs],a[sc+1]) + get_d (sc, sc+2));
	my = min (my, max(a[sc],a[sc+1]) + get_d (fs, sc+2));
	return my;
}

void out (int x) {
	printf ("%d\n", x+1);
}
void out (int x, int y) {
	printf ("%d %d\n", x+1, y+1);
}

void restore (int fs, int sc) {
	if (sc == n)  return out (fs);
	if (sc == n-1)  return out(fs,sc);

	int my = get_d (fs, sc);

	if (my == max(a[fs],a[sc]) + get_d (sc+1, sc+2)) {
		out (fs, sc);
		return restore (sc+1, sc+2);
	}
	if (my == max(a[fs],a[sc+1]) + get_d (sc, sc+2)) {
		out (fs, sc+1);
		return restore (sc, sc+2);
	}
	if (my == max(a[sc],a[sc+1]) + get_d (fs, sc+2)) {
		out (sc, sc+1);
		return restore (fs, sc+2);
	}
	throw;
}

void solve() {
	memset (d, -1, sizeof d);
	int ans = get_d (0, 1);
	cout << ans << endl;
	restore (0, 1);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}