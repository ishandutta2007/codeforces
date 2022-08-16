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
	int t; cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		bool p1 = true;
		for (int i = 1; i <= k1; ++i) {
			int a; cin >> a;
		}
		for (int i = 1; i <= k2; ++i) {
			int a; cin >> a;
			if (a == n) {
				p1 = false;
			}
		}
		if (p1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}