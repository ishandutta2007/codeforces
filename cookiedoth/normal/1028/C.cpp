/*

Code for problem C by savkinsd2089
Generated 27 Aug 2018 at 07.43 pm
The Moon is Waning Gibbous (99% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
-_-
z_z

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define y1 my_y1
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

multiset<int> x1, y1, x2, y2;
vector<int> vx1, vy1, vx2, vy2;

signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int _x1, _y1, _x2, _y2;
		cin >> _x1 >> _y1 >> _x2 >> _y2;
		x1.insert(_x1);
		y1.insert(_y1);
		x2.insert(_x2);
		y2.insert(_y2);
		vx1.push_back(_x1);
		vy1.push_back(_y1);
		vx2.push_back(_x2);
		vy2.push_back(_y2);
	}
	for (int i = 0; i < n; ++i) {
		x1.erase(x1.find(vx1[i]));
		y1.erase(y1.find(vy1[i]));
		x2.erase(x2.find(vx2[i]));
		y2.erase(y2.find(vy2[i]));
		if (*prev(x1.end()) <= (*x2.begin()) && (*prev(y1.end())) <= (*y2.begin())) {
			cout << (*x2.begin()) << " " << (*y2.begin()) << endl;
			return 0;
		}
		x1.insert(vx1[i]);
		y1.insert(vy1[i]);
		x2.insert(vx2[i]);
		y2.insert(vy2[i]);
	}
}