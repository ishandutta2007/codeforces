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

const int N = 30;

int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int tot = (1 << n);
	for (int i = 0; i < tot; ++i) {
		int s = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				s += a[j];
			} else {
				s -= a[j];
			}
		}
		s = (s % 360);
		s += 360;
		s %= 360;
		if (!s) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}