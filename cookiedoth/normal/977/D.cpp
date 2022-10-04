/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
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
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const ll MOD = 1e9 + 7;

struct number {

	ll x, c2, c3;

	number() {}

	number(ll _x) {
		x = _x;
		c2 = 0;
		c3 = 0;
		while (_x % 2 == 0) {
			_x /= 2;
			c2++;
		}
		while (_x % 3 == 0) {
			_x /= 3;
			c3++;
		}
	}

};

bool operator < (number a, number b) {
	return (a.c2 - a.c3) < (b.c2 - b.c3);
}

const int mx = 200;
number a[mx];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		a[i] = number(t);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		cout << a[i].x << " ";
	}
	cout << endl;
}