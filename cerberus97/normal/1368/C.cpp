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
#include <numeric>

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
	int n; cin >> n;
	cout << 3 * n + 4 << endl;
	cout << "0 0\n0 1\n1 0\n1 1\n";
	int x = 2, y = 2;
	while (n--) {
		cout << x << ' ' << y << '\n';
		cout << x - 1 << ' ' << y << '\n';
		cout << x << ' ' << y - 1 << '\n';
		++x; ++y;
	}
}