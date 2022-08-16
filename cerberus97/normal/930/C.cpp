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

const int N = 1e5 + 10, A = N;

int a[N], here_f[N], here_b[N], tree[4 * N];

void solve(int *a, int m, int *here);
void update(int i, int l, int r, int p, int x);
int query(int i, int l, int r, int ql, int qr);

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		++a[l];
		--a[r + 1];
	}
	int ctr = 0;
	for (int i = 1; i <= m; ++i) {
		ctr += a[i];
		a[i] = ctr;
	}
	solve(a, m, here_f);
	reverse(a + 1, a + 1 + m);
	solve(a, m, here_b);
	reverse(here_b + 1, here_b + 1 + m);
	int best = 0;
	for (int i = 1; i <= m; ++i) {
		best = max(best, here_f[i] + here_b[i] - 1);
	}
	cout << best;
}

void solve(int *arr, int m, int *here) {
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= m; ++i) {
		here[i] = 1 + query(1, 0, A, 0, arr[i]);
		update(1, 0, A, arr[i], here[i]);
	}
}

void update(int i, int l, int r, int p, int x) {
	tree[i] = max(tree[i], x);
	if (l < r) {
		int mid = (l + r) / 2;
		if (p <= mid) {
			update(2 * i, l, mid, p, x);
		} else {
			update(2 * i + 1, mid + 1, r, p, x);
		}
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2;
		return max(query(2 * i, l, mid, ql, qr), query(2 * i + 1, mid + 1, r, ql, qr));
	}
}