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
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

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
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <int> glist[200050];
int G[200050];
int in[200050];
int ch[200050];

int r[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int incnt[200050];
bool tchk[200050];
int findLastNode(int x) {
	for (auto it : glist[x]) incnt[in[it]]++;
	int st = -1;
	for (auto it : glist[x]) {
		if (incnt[it] == 0) {
			st = it;
			break;
		}
	}
	if (st == -1) return glist[x][0];

	while (1) {
		tchk[st] = true;
		if (tchk[in[st]]) return st;
		st = in[st];
	}
}

int A[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) r[i] = i;

	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		r[root(i)] = r[root(in[i])];
	}

	int gcnt = 0;
	for (i = 1; i <= N; i++) {
		if (root(i) != i) continue;
		ch[i] = ++gcnt;
	}
	for (i = 1; i <= N; i++) {
		glist[ch[root(i)]].push_back(i);
		G[i] = ch[root(i)];
	}

	int x;
	for (i = 1; i <= N; i++) if (in[i] == i) break;
	if (i <= N) x = i;
	else {
		x = findLastNode(1);
		in[x] = x;
	}

	int ans = gcnt - 1;
	if (i > N) ans++;
	printf("%d\n", ans);
	
	for (i = 1; i <= gcnt; i++) {
		if (G[x] == i) continue;
		int y = findLastNode(i);
		in[y] = x;
	}
	for (i = 1; i <= N; i++) printf("%d ", in[i]);
	return !printf("\n");
}