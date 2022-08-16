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

const int N = 1e3 + 10;

int x[N], y[N], a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		ll temp = x[i] - y[i];
		x[i] = x[i] + y[i];
		y[i] = temp;
	}
	while (true) {
		vector<int> odd;
		for (int i = 1; i <= n; ++i) {
			if (x[i] % 2) {
				odd.pb(i);
			}
		}
		if (!odd.empty() and odd.size() < n) {
			cout << odd.size() << '\n';
			for (auto& i : odd) {
				cout << i << ' ';
			}
			cout << endl;
			break;
		}
		for (int i = 1; i <= n; ++i) {
			if (x[i] % 2) {
				++x[i];
				++y[i];
			}
			x[i] /= 2;
			y[i] /= 2;
			ll temp = x[i] - y[i];
			x[i] = x[i] + y[i];
			y[i] = temp;
		}
	}
}