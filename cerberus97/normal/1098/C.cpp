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

int p[N];
ll c[N];

bool solve(int n, int k, ll s);

int main() {
	fast_cin();
	int n; ll s;
	cin >> n >> s;
	int lo = 1, hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (solve(n, mid, s)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	if (hi + 1 < n) {
		solve(n, hi + 1, s);
		cout << "Yes\n";
		for (int i = 2; i <= n; ++i) {
			cout << p[i] << ' ';
		}
		cout << endl;
	} else {
		cout << "No\n";
	}
}

bool solve(int n, int k, ll s) {
	memset(c, 0, sizeof(c));
	c[1] = 1;
	--n; --s;
	for (int i = 2; n > 0; ++i) {
		int mx = min(ll(n), k * c[i - 1]);
		ll temp = -1;
		for (int j = 1; j <= mx; ++j) {
			if (ll(i) * n + (ll(n - j) * (n - j + 1)) / 2 >= s) {
				temp = j;
			} else {
				break;
			}
		}
		if (temp == -1) {
			return false;
		}
		c[i] = temp;
		n -= temp;
		s -= temp * i;
	}
	if (s) {
		return false;
	}
	int nxt = 1;
	for (int i = 1; c[i + 1] > 0; ++i) {
		int temp = nxt + c[i], ctr = 0, cur = nxt;
		for (int j = 0; j < c[i + 1]; ++j) {
			p[temp] = cur;
			++ctr;
			if (ctr == k) {
				ctr = 0;
				++cur;
			}
			++temp;
		}
		nxt += c[i];
	}
	return true;
}