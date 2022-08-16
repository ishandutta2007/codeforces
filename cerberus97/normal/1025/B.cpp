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

const int N = 2e5 + 10;

ll a[N], b[N];

bool check(ll x, int n);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	ll t[2] = {a[1], b[1]}, sq = sqrt(max(t[0], t[1]));
	for (int i = 2; i <= sq; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (t[j] % i == 0) {
				if (check(i, n)) {
					cout << i << endl;
					return 0;
				}
				while (t[j] % i == 0) {
					t[j] /= i;
				}
			}
		}
	}
	if (t[0] > 1 and check(t[0], n)) {
		cout << t[0] << endl;
	} else if (t[1] > 1 and check(t[1], n)) {
		cout << t[1] << endl;
	} else {
		cout << -1 << endl;
	}
}

bool check(ll x, int n) {
	for (int i = 1; i <= n; ++i) {
		if (a[i] % x and b[i] % x) {
			return false;
		}
	}
	return true;
}