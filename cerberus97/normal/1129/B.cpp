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

const int N = 2500, M = 1000000;

int a[N];

int main() {
	fast_cin();
	int k; cin >> k;
	if (k <= M) {
		cout << "1\n" << -k << endl;
		return 0;
	}
	int n = 1501, d = 125000;
	while ((k + d) % 1500) {
		++d;
	}
	int c = d + (k + d) / 1500;
	for (int i = 1; i <= 1500; i += 2) {
		a[i] = 1;
		a[i + 1] = -2;
	}
	a[n - 1] -= (d - 750);
	a[n] = c;
	cout << n << endl;
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
}