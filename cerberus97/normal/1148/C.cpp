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

int p[N], loc[N];
vector<pii> ans;

void multi_swap(int i, int j, int n);
void do_swap(int i, int j);
bool ok(int i, int j, int n);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		loc[p[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i] != i) {
			multi_swap(i, loc[i], n);
		}
		assert(p[i] == i);
	}
	cout << ans.size() << '\n';
	for (auto &i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}

void multi_swap(int i, int j, int n) {
	if (ok(i, j, n)) {
		do_swap(i, j);
	} else if (ok(i, 1, n) and ok(j, 1, n)) {
		do_swap(i, 1);
		do_swap(j, 1);
		do_swap(i, 1);
	} else if (ok(i, n, n) and ok(j, n, n)) {
		do_swap(i, n);
		do_swap(j, n);
		do_swap(i, n);
	} else {
		do_swap(1, j);
		do_swap(i, n);
		do_swap(1, n);
		do_swap(1, j);
		do_swap(i, n);
	}
}

void do_swap(int i, int j) {
	ans.pb({i, j});
	swap(loc[p[i]], loc[p[j]]);
	swap(p[i], p[j]);
}

bool ok(int i, int j, int n) {
	return 2 * abs(i - j) >= n;
}