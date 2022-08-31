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

const int N = 3e5 + 10;

int a[N];

bool check(int n, int m, int t);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int lo = 0, hi = m - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(n, m, mid)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << hi + 1 << endl;
}

bool check(int n, int m, int t) {
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] + t < m) {
			if (a[i] + t < cur) {
				return false;
			} else {
				cur = max(cur, a[i]);
			}
		} else if (cur > (a[i] + t) % m) {
			cur = max(cur, a[i]);
		}
	}
	return true;
}