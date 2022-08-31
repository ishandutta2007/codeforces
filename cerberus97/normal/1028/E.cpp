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

const int N = 4e5 + 10, inf = 1e9;
ll a[N], b[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		a[i] = a[i + n] = -1;
		b[i + n] = b[i];
	}
	int p = -1;
	for (int i = n; i <= 2 * n; ++i) {
		if (b[i - 1] < b[i]) {
			p = i;
			break;
		}
	}
	if (p == -1) {
		if (b[1] > 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				cout << 1 << ' ';
			}
		}
		return 0;
	}
	cout << "YES\n";
	a[p] = a[p - n] = b[p];
	for (int i = p - 1; i > p - n; --i) {
		ll t = (b[i - 1] - b[i]) / a[i + 1] + 1;
		a[i] = t * a[i + 1] + b[i];
	}
	for (int i = 1; i <= n; ++i) {
		cout << max(a[i], a[i + n]) << ' ';
	}
}