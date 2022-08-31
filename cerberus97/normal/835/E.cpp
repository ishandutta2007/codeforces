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

const int kN = 1e3 + 10, kB = 9;

int n, x, y;

bool query(int m, int cur, int k);

int main() {
	cin >> n >> x >> y;
	int k = 0;
	for (; k <= kB; ++k) {
		if (query(0, 0, k)) {
			break;
		}
	}

	int p1 = 0;
	for (int i = 0; i < k; ++i) {
		if (!query(i + 1, p1, k)) {
			p1 |= (1 << i);
		}
	}

	int p2 = p1 | (1 << k);
	for (int i = k + 1; i <= kB; ++i) {
		if (!query(i, p1, i)) {
			p1 |= (1 << i);
		}
		if (!query(i, p2, i)) {
			p2 |= (1 << i);
		}
	}

	if (p1 > p2) {
		swap(p1, p2);
	}
	
	cout << "! " << p1 << ' ' << p2 << endl;
}

bool query(int m, int cur, int k) {
	vector <int> v;
	int mask = (1 << m) - 1;
	cur &= mask;
	for (int i = 1; i <= n; ++i) {
		if ((i & mask) == cur and !(i & (1 << k))) {
			v.pb(i);
		}
	}

	if (v.empty()) {
		return false;
	}

	cout << "? " << v.size() << ' ';
	for (auto &i : v) {
		cout << i << ' ';
	}
	cout << endl;
	int z;
	cin >> z;
	return (z == y or z == (x ^ y));
}