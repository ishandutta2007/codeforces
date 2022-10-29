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


const int N = 86;

vector<int64> fib;
int64 n;


void read() {
	scanf ("%I64d", &n);
}


bool d[N];
int64 dd[N][2];
int u[N][2], cu;

int64 get_d (int pos, int val) {
	if (pos < 0)
		return val==0;
	int64 & my = dd[pos][val];
	int & myu = u[pos][val];
	if (myu == cu)  return my;
	myu = cu;
	my = 0;

	int cur = val + d[pos];
	if (cur <= 1)
		my += get_d (pos-1, 0);
	if (cur && pos-1 >= 0 && !d[pos-1])
		my += get_d (pos-2, 1);

	return my;
}

void tupo() {
	int res = 0;
	forn(i,1<<10) {
		int s = 0;
		forn(j,10)
			if (i & (1<<j))
				s += fib[j];
		if (s == n)
			++res;
	}
	cout << res << ' ';
}

void solve() {
	int pos = -1;
	memset (d, 0, sizeof d);
	ford(i,N) {
		d[i] = (n >= fib[i]);
		if (d[i]) {
			pos = max (pos, i);
			n -= fib[i];
			--i;
		}
	}
	if (n)  throw;

	++cu;
	printf ("%d\n", get_d (pos, 0));
}



int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	fib.pb (1);
	fib.pb (2);
	for(;;) {
		int64 f = fib.back() + fib[fib.size()-2];
		if (f <= INF64)
			fib.pb (f);
		else
			break;
	}

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		//tupo();
		solve();
	}
}