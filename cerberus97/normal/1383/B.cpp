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

const int N = 1e5 + 10, B = 30;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		int win = 0;
		for (int b = B; b >= 0; --b) {
			vector<int> cnt(2, 0);
			for (auto& i : a) {
				++cnt[(i >> b) & 1];
			}
			if (cnt[1] % 2 == 1) {
				if (cnt[1] % 4 == 1 or cnt[0] % 2 == 1) {
					win = 1;
				} else {
					win = 2;
				}
				break;
			}
		}
		if (!win) {
			cout << "DRAW\n";
		} else if (win == 1) {
			cout << "WIN\n";
		} else {
			cout << "LOSE\n";
		}
	}
}