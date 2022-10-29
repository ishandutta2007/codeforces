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


vector<int64> v;
int n, k;


bool read() {
	return !! (cin >> n >> k);
}


void solve() {
	int64 fact = 1;
	for (int i=1; i<=n; ++i) {
		fact *= i;
		if (fact > k)
			break;
	}
	if (fact < k) {
		puts ("-1");
		return;
	}


	int64 f = 1;
	int pos = n;
	for (; pos>=1; --pos) {
		f *= max (1, n - pos);
		if (k <= f) {
			f /= max (1, n - pos);
			++pos;
			break;
		}
	}
	pos = max (pos, 1);

	vector<int> nums;
	for (int i=pos; i<=n; ++i)
		nums.pb (i);
	
	int ans = 0;
	for (int i=pos; i<=n; ++i) {
		int cur = (k - 1) / (int)f;
		int number = nums[cur];
		nums.erase (nums.begin() + cur);
		
		if (binary_search (all(v), number) && binary_search (all(v), i))
			++ans;

		k = 1 + (k - 1) % (int)f;
		f /= max (1, n - i);
	}

	forn(i,v.size())
		if (v[i] < pos)
			++ans;
	cout << ans << endl;
}



int main() {
	v.pb (0);
	forn(i,v.size()) {
		int64 c = v[i] * 10ll + 4;
		if (c < 1E11) {
			v.pb (c);
			v.pb (c + 3);
		}
	}
	sort (all (v));
	v.erase (v.begin());

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