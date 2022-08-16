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

const int N = 2e5 + 10, LGN = log2(N) + 2;

int a[N], l[N], r[N], mn[N][LGN];

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		r[a[i]] = i;
	}
	for (int i = n; i >= 1; --i) {
		l[a[i]] = i;
	}
	if (l[q] == 0) {
		if (l[0] == 0) {
			cout << "NO\n";
			return 0;
		} else {
			a[l[0]] = q;
			l[q] = r[q] = l[0];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			if (i - 1 >= 1 and a[i - 1] != 0) {
				a[i] = a[i - 1];
			} else {
				for (int j = i + 1; j <= n; ++j) {
					if (a[j]) {
						a[i] = a[j];
						break;
					}
				}
			}
		}
		mn[i][0] = a[i];
	}
	for (int j = 1; j < LGN; ++j) {
		int len = (1 << j);
		for (int i = 1; i + len - 1 <= n; ++i) {
			mn[i][j] = min(mn[i][j - 1], mn[i + len / 2][j - 1]);
		}
	}
	for (int i = q; i >= 1; --i) {
		if (l[i] == 0) {
			continue;
		}
		int len = (r[i] - 1) - (l[i] + 1) + 1;
		int p = l[i] + 1;
		int ans = i + 1;
		for (int j = LGN - 1; j >= 0; --j) {
			if (len >= (1 << j)) {
				ans = min(ans, mn[p][j]);
				p += (1 << j);
				len -= (1 << j);
			}
		}
		if (ans < i) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}