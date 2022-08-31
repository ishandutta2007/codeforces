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

const int N = 2e5 + 10;

int a[N], qt[N], qp[N], qx[N];
bool done[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> qt[i];
		if (qt[i] == 1) {
			cin >> qp[i] >> qx[i];
		} else {
			cin >> qx[i];
		}
	}
	int mx = 0;
	for (int i = q; i >= 1; --i) {
		if (qt[i] == 2) {
			mx = max(mx, qx[i]);
		} else if (!done[qp[i]]) {
			done[qp[i]] = true;
			a[qp[i]] = max(qx[i], mx);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!done[i]) {
			a[i] = max(a[i], mx);
		}
		cout << a[i] << ' ';
	}
	cout << endl;
}