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
	int l = 1, r = n;
	auto query = [&](int i) {
		cout << "? " << i << endl;
		int ans; cin >> ans;
		return ans;
	};
	while (l < r) {
		int m1 = (l + r) / 2, m2 = m1 + 1;
		int v1 = query(m1), v2 = query(m2);
		if (v1 < v2) {
			r = m1;
		} else {
			l = m2;
		}
	}
	cout << "! " << l << endl;
}