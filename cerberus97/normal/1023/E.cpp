/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 500 + 10;

int n;

bool query(int r1, int c1, int r2, int c2);

int main() {
	cin >> n;
	int r = 1, c = 1;
	int half = n - 1;
	string p1 = "! ", p2 = "";
	while (half--) {
		if (r < n and query(r + 1, c, n, n)) {
			++r;
			p1 += 'D';
		} else {
			++c;
			p1 += 'R';
		}
	}
	half = n - 1;
	r = n; c = n;
	while (half--) {
		if (c > 1 and query(1, 1, r, c - 1)) {
			--c;
			p2 += 'R';
		} else {
			--r;
			p2 += 'D';
		}
	}
	reverse(p2.begin(), p2.end());
	cout << p1 + p2 << endl;
}

bool query(int r1, int c1, int r2, int c2) {
	if (r2 - r1 + c2 - c1 < n - 1) {
		assert(false);
	}
	cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
	string ans; cin >> ans;
	if (ans == "YES") {
		return true;
	} else if (ans == "BAD") {
		exit(0);
	} else {
		return false;
	}
}