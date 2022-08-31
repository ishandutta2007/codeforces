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
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	if (n == 1) {
		for (int i = 0; i < 3; ++i) {
			cout << 1 << ' ' << 1 << '\n';
			cout << (i ? 0 : -a[0]) << '\n';
		}
		return 0;
	}
	cout << 1 << ' ' << n << '\n';
	for (int i = 0; i < n - 1; ++i) {
		cout << -a[i] * n << ' ';
	}
	cout << 0 << '\n';
	cout << 1 << ' ' << n - 1 << '\n';
	for (int i = 0; i < n - 1; ++i) {
		cout << a[i] * (n - 1) << ' ';
	}
	cout << '\n';
	cout << n << ' ' << n << '\n';
	cout << -a[n - 1] << '\n';
}