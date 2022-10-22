/* 	* In the name of GOD  */

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 70016;
bitset <N> b, wef, x;
int par[N];
int a[N];
bool f[N];
pair <int, vector <int>> ans[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, s;
	cin >> n >> s;
	int mx = 0, in = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > mx) {
			mx = a[i];
			in = i;
		}
	}
	if (mx > s) {
		cout << -1 << '\n';
		return 0;
	}
	b[mx] = true;
	par[mx] = in;
	for (int i = 0; i < n; i++) {
		if (i == in)
			continue;
		wef = b;
		wef <<= a[i];
		x = ((~b) & wef);
		int k = -1;
		while (true) {
			int j;
			if (k == -1) {
				j = x._Find_first();
			} else {
				j = x._Find_next(k);
			}
			if (j == N)
				break;
			par[j] = i;
			k = j;
		}
		b |= wef;
	}
	if (!b[s]) {
		cout << -1 << '\n';
		return 0;
	}
	int x = s;
	while (x != 0) {
		f[par[x]] = true;
		x -= a[par[x]];
	}
	vector <pair <int, int>> p;
	for (int i = 0; i < n; i++) {
		if (f[i] && i != in) {
			ans[i].F = a[i];
			ans[i].S.clear();
		} else {
			p.push_back(make_pair(a[i], i));
		}
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < (int)p.size(); i++) {
		ans[p[i].S].F = a[p[i].S] - (int)(i != 0 ? a[p[i - 1].S] : 0);
		if (i != 0)
			ans[p[i].S].S.push_back(p[i - 1].S);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i].F << ' ' << ans[i].S.size() << ' ';
		for (int x : ans[i].S)
			cout << x + 1 << ' ';
		cout << '\n';
	}
}