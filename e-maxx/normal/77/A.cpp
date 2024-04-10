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


#define forn(i,n)  for (int i=0; i<int(n); ++i)


const int N = 7;

bool g[N][N];
map<string,int> m;
int d[3];


bool read() {
	int n;
	if (! (cin >> n))
		return false;
	memset (g, 0, sizeof g);
	forn(i,n) {
		string a, b, c;
		cin >> a >> b >> c;
		g[m[a]][m[c]] = true;
	}
	forn(i,3)
		cin >> d[i];
	return true;
}


int get (int msk, int i) {
	int b = 0;
	forn(i,N)
		if (msk & (1<<i))
			++b;
	return d[i] / b;
}

int get_s (int msk) {
	int res = 0;
	forn(i,N)
		forn(j,N)
			if (g[i][j] && (msk & (1<<i)) && (msk & (1<<j)))
				++res;
	return res;
}

void solve() {
	int bval = 2100000000;
	int bsymp;
	forn(a,1<<N)
		forn(b,1<<N)
			if (! (a & b)) {
				int c = (1<<N)-1 - a - b;
				if (!a || !b || !c)
					continue;

				int v[3] = {
					get (a, 0),
					get (b, 1),
					get (c, 2)
				};
				int val = * max_element (v, v+3) - * min_element (v, v+3);
				int symp = get_s (a) + get_s (b) + get_s (c);
				if (val < bval || val == bval && symp > bsymp)
					bval = val,  bsymp = symp;
			}

	cout << bval << ' ' << bsymp << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	m["Anka"] = 0;
	m["Chapay"] = 1;
	m["Cleo"] = 2;
	m["Troll"] = 3;
	m["Dracul"] = 4;
	m["Snowy"] = 5;
	m["Hexadecimal"] = 6;

	while (read())
		solve();

}