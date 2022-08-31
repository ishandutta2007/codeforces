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

char a[N];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	cin >> (a + 1);
	bool can_win = false, can_block = false;
	for (char j = '0'; j <= '1'; ++j) {
		int l = n + 1, r = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == j) {
				l = min(l, i);
				r = max(r, i);
			}
		}
		if (r - l + 1 <= k) {
			can_win = true;
		} else if (r - l + 1 >= k + 2 or l > k or r + k <= n) {
			can_block = true;
		}
	}
	if (can_win) {
		cout << "tokitsukaze\n";
	} else if (can_block) {
		cout << "once again\n";
	} else {
		cout << "quailty\n";
	}
}