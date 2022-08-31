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

const int N = 1e6 + 10;

bool solve(int l, int lr);

int main() {
	fast_cin();
	int n; cin >> n;
	int x = 0;
	while ((1 << (x + 1)) - 1 <= n) {
		++x;
	}
	int lr = n - ((1 << x) - 1), l = (1 << (x - 1)) - lr;
	if (l >= 0 and solve(l, lr)) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
}

bool solve(int l, int lr) {
	if (l + lr == 1) {
		return true;
	} else if (l > lr) {
		return false;
	} else {
		return solve((lr - l) / 2, l);
	}
}