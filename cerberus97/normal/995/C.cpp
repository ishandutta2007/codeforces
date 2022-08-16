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
#include <cassert>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M = 15e5;
const ll LIM = ll(M) * M, T = 1e7, inf = 1e18;


struct vec {
	ll x, y; int idx;
	vec operator+(vec &v2) {
		return {x + v2.x, y + v2.y, idx};
	}
	vec operator-(vec &v2) {
		return {x - v2.x, y - v2.y, idx};
	}
} v[N];

int nxt_idx;
int l[2 * N], r[2 * N];
bool par[2 * N], ans[N];

void reduce(int i);
void dfs(int i, bool b);
void flip(vec &v);
ll len2(vec v1);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i].x >> v[i].y;
		v[i].idx = i;
		l[i] = r[i] = i;
	}
	nxt_idx = n + 1;
	for (int i = 1; i <= n - 2; ++i) {
		reduce(i);
	}
	if (len2(v[n - 1] + v[n]) > LIM) {
		flip(v[n]);
	}
	assert(len2(v[n - 1] + v[n]) <= LIM);
	dfs(v[n - 1].idx, 0);
	dfs(v[n].idx, 0);
	for (int i = 1; i <= n; ++i) {
		cout << (par[i] ? -1 : 1) << ' ';
	}
}

void reduce(int i) {
	while (true) {
		ll target = max(len2(v[i]), len2(v[i + 1]));
		if (len2(v[i] + v[i + 1]) <= target or len2(v[i] - v[i + 1]) <= target) {
			if (len2(v[i] - v[i + 1]) <= target) {
				flip(v[i + 1]);
			}
			v[i + 1] = v[i + 1] + v[i];
			r[nxt_idx] = v[i + 1].idx;
			l[nxt_idx] = v[i].idx;
			v[i + 1].idx = nxt_idx++;
			break;
		}
		swap(v[i], v[i + 1]);
		swap(v[i + 1], v[i + 2]);
	}
}

void dfs(int i, bool b) {
	par[i] ^= b;
	if (l[i] != r[i]) {
		dfs(l[i], par[i]);
		dfs(r[i], par[i]);
	}
}

void flip(vec &v1) {
	v1.x = -v1.x;
	v1.y = -v1.y;
	par[v1.idx] = !par[v1.idx];
}

ll len2(vec v1) {
	if (abs(v1.x) > T or abs(v1.y) > T) {
		return inf;
	}
	return (v1.x * v1.x + v1.y * v1.y);
}