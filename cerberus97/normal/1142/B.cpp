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

	const int N = 2e5 + 10, LOG = log2(N) + 2;

	int a[N], b[N], pos[N], nxt[N];
	int jump[N][LOG], ans[N];

	int main() {
		fast_cin();
		int n, m, q;
		cin >> n >> m >> q;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			nxt[a[i - 1]] = a[i];
			pos[i] = m + 1;
		}
		nxt[a[n]] = a[1];
		for (int i = 1; i <= m; ++i) {
			cin >> b[i];
		}
		for (int j = 0; j < LOG; ++j) {
			jump[m + 1][j] = m + 1;
		}
		ans[m + 1] = m + 1;
		for (int i = m; i >= 1; --i) {
			jump[i][0] = pos[nxt[b[i]]];
			for (int j = 1; j < LOG; ++j) {
				jump[i][j] = jump[jump[i][j - 1]][j - 1];
			}
			int temp = n - 1, u = i;
			for (int j = LOG; j >= 0; --j) {
				if ((1 << j) <= temp) {
					u = jump[u][j];
					temp -= (1 << j);
				}
			}
			// cout << i << ' ' << u << endl;
			ans[i] = min(ans[i + 1], u);
			pos[b[i]] = i;
		}
		while (q--) {
			int l, r;
			cin >> l >> r;
			if (ans[l] <= r) {
				cout << '1';
			} else {
				cout << '0';
			}
		}
		cout << endl;
	}