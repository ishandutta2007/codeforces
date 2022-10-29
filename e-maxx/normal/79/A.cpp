#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)


int x, y;


bool read() {
	return !! (cin >> x >> y);
}


bool a() {
	for (int i=2; i>=0; --i)
		if (i<=x && (22-10*i)<=y) {
			x -= i;
			y -= 22-10*i;
			return true;
		}
	return false;
}


bool b() {
	for (int i=0; i<=2; ++i)
		if (i<=x && (22-10*i)<=y) {
			x -= i;
			y -= 22-10*i;
			return true;
		}
	return false;
}

void solve() {
	for(;;) {
		if (!a()) {
			puts ("Hanako");
			break;
		}
		if (!b()) {
			puts ("Ciel");
			break;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}