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

const int N = 1e5 + 10, C = 100;

int main() {
	fast_cin();
	int n, p;
	cin >> n >> p;
	for (int cnt = 1; cnt <= C; ++cnt) {
		int target = n - p * cnt;
		if (target < 0) {
			break;
		}
		int bits = __builtin_popcount(target);
		if (bits <= cnt and cnt <= target) {
			cout << cnt << '\n';
			return 0;
		}
	}
	cout << -1 << endl;
}