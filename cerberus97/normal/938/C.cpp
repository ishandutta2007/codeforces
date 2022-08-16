/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, MX = 1e9;

void solve(int x);

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		solve(x);
	}
}

void solve(int x) {
	if (!x) {
		cout << "1 1\n";
		return;
	}
	int sq = sqrt(x);
	for (int i = 1; i <= sq; ++i) {
		if (x % i) {
			continue;
		}
		int p = i, q = x / i;
		if ((p & 1) != (q & 1)) {
			continue;
		}
		int n = (p + q) / 2, k = (q - p) / 2;
		if (!k) {
			continue;
		}
		int m = n / k;
		if (n / m == k and n <= MX) {
			cout << n << ' ' << m << endl;
			return;
		}
	}
	cout << "-1\n";
}