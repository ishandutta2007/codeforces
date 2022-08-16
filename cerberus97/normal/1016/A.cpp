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

int a[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int left = m;
	for (int i = 1; i <= n; ++i) {
		// cout << endl << i << ' ' << a[i] << ' ' << left << endl;
		if (a[i] < left) {
			left -= a[i];
			cout << 0 << ' ';
		} else {
			int turns = 1;
			a[i] -= left;
			turns += a[i] / m;
			left = m - (a[i] % m);
			if (left == 0) {
				left = m;
			}
			cout << turns << ' ';
		}
		// cout << endl << i << ' ' << left << endl;
	}
}