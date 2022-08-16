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
#include "bitset"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int kN = 2e2 + 10, kL = 10, kS = (1 << kL) + 10;

struct BigString {
	string l, r;
	bitset<kS> has[kL];
	int k = 0;
};

BigString a[kN];

void update(int i);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		int sz = s.size();
		a[i].l = s.substr(0, kL);
		a[i].r = s.substr(max(0, sz - kL), kL);
		for (int l = 0; l < sz; ++l) {
			int temp = 0;
			for (int r = l; r < l + kL and r < sz; ++r) {
				temp = (temp << 1) | (s[r] == '1');
				a[i].has[r - l][temp] = 1;
			}
		}
		update(i);
	}

	int m;
	cin >> m;
	for (int i = n + 1; i <= m + n; ++i) {
		int x, y;
		cin >> x >> y;
		a[i].l = (a[x].l + a[y].l).substr(0, kL);
		int s1 = a[x].r.size(), s2 = a[y].l.size();
		int sz = a[x].r.size() + a[y].r.size();
		a[i].r = (a[x].r + a[y].r).substr(max(0, sz - kL), kL);
		for (int j = 0; j < kL; ++j) {
			a[i].has[j] = a[x].has[j] | a[y].has[j];
		}

		int st = 0;
		for (int l = s1 - 1; l >= 0; --l) {
			st |= ((a[x].r[l] == '1') << (s1 - l - 1));
			int temp = st;
			for (int r = 0; (s1 - l) + (r + 1) <= kL and r < s2; ++r) {
				temp = (temp << 1) | (a[y].l[r] == '1');
				a[i].has[r + s1 - l][temp] = 1;
			}
		}

		a[i].k = max(a[x].k, a[y].k);
		update(i);
		cout << a[i].k << endl;
	}
}

void update(int i) {
	while (a[i].k < kL) {
		int k = a[i].k + 1, mx = (1 << (a[i].k + 1));
		for (int j = 0; j < mx; ++j) {
			if (a[i].has[k - 1][j] == 0) {
				return;
			}
		}
		++a[i].k;
	}
}