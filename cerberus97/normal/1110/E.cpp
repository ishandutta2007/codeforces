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

ll c[N], d[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	vector<ll> v1, v2;
	for (int i = 2; i <= n; ++i) {
		v1.pb(c[i] - c[i - 1]);
		v2.pb(d[i] - d[i - 1]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (v1 == v2 and c[1] == d[1]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}