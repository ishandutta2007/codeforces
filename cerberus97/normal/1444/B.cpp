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

const int N = 1e5 + 10, mod = 998244353;

int add(int a, int b) {
	return (a + b) % mod;
}

int sub(int a, int b) {
	return (a - b + mod) % mod;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int pwr(int x, int e) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(2 * n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = add(sum, sub(a[2 * n - i - 1], a[i]));
	}
	int ways = 1;
	for (int i = n + 1; i <= 2 * n; ++i) {
		ways = mul(ways, i);
	}
	for (int i = 1; i <= n; ++i) {
		ways = mul(ways, pwr(i, mod - 2));
	}
	cout << mul(sum, ways) << '\n';
}