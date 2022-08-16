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

const int N = 2e5 + 10, C = 300;

char s[N];
int tree[4 * N];
bool deleted[N];
set <int> pos[C];

void build(int i, int l, int r);
void update(int i, int l, int r, int p, int x);
int walk(int i, int l, int r, int p);

int main() {
	int n, m;
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		pos[s[i]].insert(i);
	}

	build(1, 1, n);
	while (m--) {
		int l, r; char c;
		cin >> l >> r >> c;
		l = walk(1, 1, n, l);
		r = walk(1, 1, n, r);
		auto p = pos[c].lower_bound(l);
		vector <int> temp;
		while (p != pos[c].end() and *p <= r) {
			temp.pb(*p);
			deleted[*p] = true;
			update(1, 1, n, *p, -1);
			++p;
		}

		for (auto &i : temp) {
			pos[c].erase(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!deleted[i]) {
			cout << s[i];
		}
	}
}

void build(int i, int l, int r) {
	tree[i] = r - l + 1;
	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
}

void update(int i, int l, int r, int p, int x) {
	--tree[i];
	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	if (p <= mid) {
		update(2 * i, l, mid, p, x);
	} else {
		update(2 * i + 1, mid + 1, r, p, x);
	}
}

int walk(int i, int l, int r, int p) {
	if (l == r) {
		return l;
	}

	int mid = (l + r) / 2;
	if (tree[2 * i] >= p) {
		return walk(2 * i, l, mid, p);
	} else {
		return walk(2 * i + 1, mid + 1, r, p - tree[2 * i]);
	}
}