#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 110000;
const double EPS = 1E-9;


int maxa, maxb, w;

bool read() {
	return !! (cin >> maxa >> maxb >> w);
}


struct cmp {
	bool operator() (double a, double b) const {
		return a < b - EPS;
	}
};

double val[MAXN];
map < double, vector<int>, cmp > m;


int rev (int x) {
	static char buf[20];
	_itoa (x, buf, 10);
	reverse (buf, buf+strlen(buf));
	return atoi (buf);
}

int solve_a (int a, int b) {
	vector<int> & my = m[1./val[a]];
	return int (upper_bound (my.begin(), my.end(), b) - my.begin());
}
int solve_b (int b, int a) {
	return solve_a (b, a);
}

int tupo (int a, int b) {
	int res = 0;
	for (int i=1; i<=a; ++i)
		for (int j=1; j<=b; ++j)
			if (abs(val[i] * val[j] - 1) < EPS)
				++res;
	return res;
}

void solve() {
	m.clear();
	for (int i=1; i<=max(maxa,maxb); ++i)
		m[val[i] = i * 1. / rev(i)].push_back (i);

	int ba=-1, bb=-1;
	for (int a=1, b=1, c=1; a<=maxa; ) {
		while (c < w && b < maxb)
			c += solve_b (++b, a);
		while (b > 1 && c - solve_b (b, a) >= w)
			c -= solve_b (b--, a);
		if (c >= w)
			if (ba == -1 || a * 1ll * b < ba * 1ll * bb)
				ba=a, bb=b;

		//if (c != tupo (a, b))
		//	throw;
		c += solve_a (++a, b);
	}
	if (ba == -1)
		cout << -1 << endl;
	else
		cout << ba << ' ' << bb << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	if (read())
		solve();

}