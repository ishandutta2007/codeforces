/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int answer(int x, int y);

int main() {
	fast_cin();
	int n; cin >> n;
	int col_left = answer(0, 1);
	int pl = 1, pr = 1000000000;
	--n;
	while (n--) {
		int mid = (pl + pr + (n & 1)) / 2;
		int col = answer(mid, 1);
		if (col == col_left) {
			pl = mid + 1;
		} else {
			pr = mid - 1;
		}
		// assert(pl <= pr);
	}
	cout << pl - 1 << ' ' << 2 << ' ' << pl << ' ' << 0 << endl;
}

int answer(int x, int y) {
	cout << x << ' ' << y << endl;
	string s; cin >> s;
	return s == "black";
	// return true;
}