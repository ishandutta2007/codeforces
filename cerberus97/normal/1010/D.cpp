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

const int N = 1e6 + 10;

int l[N], r[N];
bool flip[N], val[N];
string type[N];

void dfs1(int u);
void dfs2(int u);
bool eval(string type, int a, int b);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> type[i];
		if (type[i] == "IN") {
			cin >> val[i];
		} else if (type[i] == "NOT") {
			cin >> l[i];
		} else {
			cin >> l[i] >> r[i];
		}
	}
	dfs1(1);
	dfs2(1);
	for (int i = 1; i <= n; ++i) {
		if (type[i] == "IN") {
			cout << (val[1] xor flip[i]);
		}
	}
}

void dfs1(int u) {
	if (type[u] == "IN") {
		return;
	}
	if (l[u]) {
		dfs1(l[u]);
	}
	if (r[u]) {
		dfs1(r[u]);
	}
	val[u] = eval(type[u], val[l[u]], val[r[u]]);
}

void dfs2(int u) {
	if (type[u] == "IN") {
		flip[u] = true;
	} else if (type[u] == "NOT") {
		dfs2(l[u]);
	} else if (type[u] == "XOR") {
		dfs2(l[u]);
		dfs2(r[u]);
	} else {
		if (eval(type[u], !val[l[u]], val[r[u]]) != val[u]) {
			dfs2(l[u]);
		}
		if (eval(type[u], val[l[u]], !val[r[u]]) != val[u]) {
			dfs2(r[u]);
		}
	}
}

bool eval(string t, int a, int b) {
	if (t == "NOT") {
		return !a;
	} else if (t == "XOR") {
		return a xor b;
	} else if (t == "AND") {
		return a and b;
	} else {
		return a or b;
	}
}