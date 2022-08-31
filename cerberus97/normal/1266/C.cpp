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

int main() {
	fast_cin();
	int r, c;
	cin >> r >> c;
	if (r * c == 1) {
		cout << 0 << '\n';
		return 0;
	} else if (c == 1) {
		for (int i = c + 1; i <= c + r; ++i) {
			for (int j = 1; j <= c; ++j) {
				cout << (i * j) << ' ';
			}
			cout << '\n';
		}
		return 0;
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = r + 1; j <= r + c; ++j) {
			cout << (i * j) << ' ';
		}
		cout << '\n';
	}
}