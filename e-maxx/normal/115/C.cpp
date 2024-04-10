#pragma comment (linker, "/STACK:200000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MOD = 1000003;


int n, m;
vector<string> a;


bool read() {
	if (! (cin >> n >> m))  return false;
	a.resize (n);
	forn(i,n) {
		a[i] = string (m, ' ');
		forn(j,m)
			scanf (" %c", &a[i][j]);
	}
	return true;
}

void gen() {
	n = m = 1000;
	a.assign (n, string (m, '.'));
}


void mirror() {
	vector<string> b (m);
	forn(i,m) {
		b[i] = string (n, ' ');
		forn(j,n)
			b[i][j] = a[j][i];
	}
	a = b;
	swap (n, m);
}

bool is_ok (char c, int x, int step) {
	if (c == '.')  return true;
	int b1 = c<='2';
	int b2 = c=='1' || c=='4';
	return (step==0 ? b1 : b2) == x;
}

int solve_real (int step) {
	int ans = 1;
	forn(i,n) {
		int cans = 0;
		forn(start,2) {
			bool ok = true;
			forn(j,m)
				ok &= is_ok (a[i][j], start ^ (j&1), step);
			cans += ok;
		}
		ans = ans * cans % MOD;
	}
	return ans;
}


void solve() {
	int ans1 = solve_real (0);
	mirror();
	int ans2 = solve_real (1);

	int64 ans = ans1 * 1ll * ans2 % MOD;
	cout << ans << endl;
}



int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}