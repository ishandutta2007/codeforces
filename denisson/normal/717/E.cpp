#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TASK "twopaths"

const int dd = (int)1e5 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int C[dd];
vector<int> ans, G[dd];

void rev(int v) {
	C[v] ^= 1;
}

void dfs(int v, int p = -1) {
	ans.push_back(v);
	for (auto to : G[v]) {
		if (to != p) {
			rev(to);
			dfs(to, v);
			ans.push_back(v);
			rev(v);
		}
	}
	if (C[v] == 0 && v != 0) {
		ans.push_back(p);
		rev(p);
		ans.push_back(v);
		rev(v);
	}
}

int main() {
	file();
	int n, kkk = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &C[i]);
		if (C[i] == -1) {
			C[i] = 0;
			++kkk;
		}
	}
	if (kkk == 0) {
		puts("1");
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x - 1].push_back(y - 1);
		G[y - 1].push_back(x - 1);
	}
	dfs(0);
	if (C[0] == 0) {
		ans.pop_back();
	}
	for (auto i : ans) {
		printf("%d ", i + 1);
	}
	return 0;
}