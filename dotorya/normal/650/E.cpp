#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 100000000;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

const int NMX = 500000 + 50;
int r[NMX];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

pii in1[500050];
pii in2[500050];

vector <pair<int, pii>> conn1[500050];
vector <pair<int, pii>> conn2[500050];
pair<int, pii> par1[500050];
pair<int, pii> par2[500050];
void DFS1(int n) {
	for (auto it : conn1[n]) {
		if (par1[n].first == it.first) continue;
		par1[it.first].first = n;
		par1[it.first].second = it.second;
		DFS1(it.first);
	}
}
void DFS2(int n) {
	for (auto it : conn2[n]) {
		if (par2[n].first == it.first) continue;
		par2[it.first].first = n;
		par2[it.first].second = it.second;
		DFS2(it.first);
	}
}
void DFS3(int n) {
	if (n != root(1)) printf("%d %d %d %d\n", par1[n].second.first, par1[n].second.second, par2[n].second.first, par2[n].second.second);
	for (auto it : conn2[n]) {
		if (par2[n].first == it.first) continue;
		DFS3(it.first);
	}
}
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i < N; i++) {
		scanf("%d %d", &in1[i].first, &in1[i].second);
		if (in1[i].first > in1[i].second) swap(in1[i].first, in1[i].second);
	}
	for (i = 1; i < N; i++) {
		scanf("%d %d", &in2[i].first, &in2[i].second);
		if (in2[i].first > in2[i].second) swap(in2[i].first, in2[i].second);
	}

	sort(in1 + 1, in1 + N);
	sort(in2 + 1, in2 + N);

	int p1 = 1, p2 = 1;
	int ans = N - 1;
	while (p1 < N && p2 < N) {
		if (in1[p1] == in2[p2]) {
			t1 = in1[p1].first, t2 = in1[p1].second;
			if (root(t1) != root(t2)) r[root(t1)] = root(t2);
			p1++, p2++;
			ans--;
		}
		else if (in1[p1] > in2[p2]) p2++;
		else p1++;
	}

	for (i = 1; i < N; i++) {
		t1 = in1[i].first, t2 = in1[i].second;
		if (root(t1) == root(t2)) continue;
		conn1[root(t1)].push_back(mp(root(t2), pii(t1, t2)));
		conn1[root(t2)].push_back(mp(root(t1), pii(t2, t1)));
	}
	for (i = 1; i < N; i++) {
		t1 = in2[i].first, t2 = in2[i].second;
		if (root(t1) == root(t2)) continue;
		conn2[root(t1)].push_back(mp(root(t2), pii(t1, t2)));
		conn2[root(t2)].push_back(mp(root(t1), pii(t2, t1)));
	}

	printf("%d\n", ans);
	DFS1(root(1));
	DFS2(root(1));
	DFS3(root(1));
}