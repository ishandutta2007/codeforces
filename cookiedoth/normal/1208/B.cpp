/*

Code for problem B by cookiedoth
Generated 25 Aug 2019 at 05.34 P


 ] 
 
Il] 


=_=
>_<
o_O

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 2010;
int n, a[mx], cnt[mx];
vector<int> coords;

int check(int l, int r) {
	//cerr << "? " << l << " " << r << endl;
	if (r == n) {
		return 1;
	}
	fill(cnt, cnt + n, 0);
	for (int i = 0; i < n; ++i) {
		if (l <= i && i <= r) {
			continue;
		}
		if (cnt[a[i]]) {
			return 0;
		}
		cnt[a[i]]++;
	}
	//cerr << "check " << l << " " << r << endl;
	return 1;
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		coords.push_back(a[i]);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(all(coords), a[i]) - coords.begin();
	}
	int ans = n;
	for (int i = 0; i < n; ++i) {
		int l = i - 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(i, mid)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		if (l != n) {
			chkmin(ans, l - i + 1);
		}
	}
	cout << ans << endl;
}