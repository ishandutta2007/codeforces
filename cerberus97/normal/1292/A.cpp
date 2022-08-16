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

int lava[3][N];
bool ok[N];

void check(int c, int n, int& cnt);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	int cnt = n - 1;
	for (int i = 1; i < n; ++i) {
		ok[i] = true;
	}
	while (q--) {
		int r, c;
		cin >> r >> c;
		lava[r][c] ^= 1;
		check(c - 1, n, cnt);
		check(c, n, cnt);
		if (cnt == n - 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}

void check(int c, int n, int& cnt) {
	if (c >= n or c < 1) {
		return;
	}
	cnt -= ok[c];
	ok[c] = false;
	for (int r = 1; r <= 2; ++r) {
		ok[c] |= (!lava[r][c] and !lava[r][c + 1]);
	}
	cnt += ok[c];
}