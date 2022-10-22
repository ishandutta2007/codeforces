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
const int N = 403, M = 26;
string s[N], t[N];
bitset <N> b[M][N];
bitset <N> ans[N], wef[N];
bitset <N> lol;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			lol[j] = true;
			ans[i][j] = true;
			int c = s[i][j] - 'a';
			b[c][i][j] = true;
		}
	}
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> t[i];
		for (int j = 0; j < c; j++) {
			if (t[i][j] == '?')
				continue;
			int c = t[i][j] - 'a';
			for (int k = 0; k < n; k++) {
				wef[k] = b[c][k];
				int jj = (j % m);
				bitset <N> x = wef[k] << (m - jj);
				wef[k] >>= jj;
				wef[k] |= x;
				wef[k] &= lol;
				ans[k] &= wef[k];
			}
		}
		for (int c = 0; c < 26; c++) {
			for (int j = 0; j < n - 1; j++) {
				swap(b[c][j], b[c][j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ans[i][j];
		cout << '\n';
	}
}