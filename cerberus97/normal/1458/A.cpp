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
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& j : b) {
		cin >> j;
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	ll d = 0;
	for (int i = 0; i < n - 1; ++i) {
		d = __gcd(d, a[i + 1] - a[i]);
	}
	for (int j = 0; j < m; ++j) {
		cout << __gcd(d, a[0] + b[j]) << ' ';
	}
	cout << endl;
}