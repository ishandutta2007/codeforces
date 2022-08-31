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

const int N = 1e5 + 10, M = 1e5;

char lo[N], hi[N];
ll ans = 0;
vector<pii> moves;

void add(int i, int j, int x, string &a);

int main() {
	fast_cin();
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < n; ++i) {
		lo[i] = '0';
		hi[i] = '9';
	}
	lo[0] = '1';
	int p = 1;
	bool ok = true;
	for (int i = 0; i < n - 1;) {
		if (a[i] == b[i]) {
			++i;
		} else if (a[i] < b[i] and a[i + 1] != hi[i + 1]) {
			add(i, i + 1, 1, a);
			p = i + 1;
		} else if (a[i] > b[i] and a[i + 1] != lo[i + 1]) {
			add(i, i + 1, -1, a);
			p = i + 1;
		} else {
			p = max(p, i + 2);
			while (p < n) {
				if (a[p - 1] == lo[p - 1] and a[p] == hi[p]) {
					++p;
				} else if (a[p - 1] == hi[p - 1] and a[p] == lo[p]) {
					++p;
				} else {
					break;
				}
			}
			if (p == n) {
				ok = false;
				break;
			}
			if (a[i] < b[i]) {
				add(i, p, 1, a);
			} else {
				add(i, p, -1, a);
			}
		}
	}
	if (ok and a[n - 1] == b[n - 1]) {
		cout << ans << '\n';
		moves.resize(min(ans, ll(M)));
		for (auto &m : moves) {
			cout << m.first << ' ' << m.second << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}

void add(int i, int j, int x, string &a) {
	int sign = x;
	if (i % 2 == j % 2) {
		sign *= -1;
	}
	if (ans < M) {
		for (int p = j - 1; p >= i; --p) {
			a[p] += sign;
			a[p + 1] += sign;
			moves.pb({p + 1, sign});
			sign *= -1;
		}
	} else {
		a[i] += x;
		a[j] += sign;
	}
	ans += (j - i);
}