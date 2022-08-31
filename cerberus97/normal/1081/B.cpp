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

const int N = 1e5 + 10;

int a[N], b[N], ctr[N], color[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = n - 1 - a[i];
	}
	int nxt_color = 1;
	for (int i = 1; i <= n; ++i) {
		if (ctr[a[i]] == 0) {
			color[a[i]] = nxt_color++;
		}
		b[i] = color[a[i]];
		++ctr[a[i]];
		if (ctr[a[i]] == a[i] + 1) {
			ctr[a[i]] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ctr[i]) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	for (int i = 1; i <= n; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;
}