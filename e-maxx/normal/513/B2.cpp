#pragma comment(linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
//#define double long double
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i, n)  for (int i = 0; i < int(n); ++i)
#define ford(i, n)  for (int i=int(n) - 1; i >= 0; --i)
#define fore(i, l, r)  for (int i = int(l); i < int(r); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


int n;
int64 m;


bool read() {
	return !!(cin >> n >> m);
}


vector<int> get(int n, int64 m) {
	if (n == 1) {
		if (m != 1)
			throw;
		return vector<int>(1, 1);
	}

	int64 half = 1LL << (n - 2);
	if (m <= half) {
		vector<int> ans = get(n - 1, m);
		forn(i, ans.size())
			++ans[i];
		ans.insert(ans.begin(), 1);
		return ans;
	} else {
		vector<int> ans = get(n - 1, m - half);
		forn(i, ans.size())
			++ans[i];
		ans.push_back(1);
		return ans;
	}
}

void solve() {
	vector<int> ans = get(n, m);
	forn(i, n)
		cout << ans[i] << ' ';
	cout << endl;
}


int main() {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	while (read())
		solve();
#else
	if (!read())
		throw;
	solve();
#endif
}