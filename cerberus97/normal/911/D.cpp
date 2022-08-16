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

const int N = 2e3 + 10;

int a[N];

int main() {
	fast_cin();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int ctr = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[i] > a[j]) {
				ctr ^= 1;
			}
		}
	}

	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		int k = (r - l + 1);
		if (((k * (k - 1)) / 2) & 1) {
			ctr ^= 1;
		}

		if (ctr & 1) {
			cout << "odd\n";
		} else {
			cout << "even\n";
		}
	}
}