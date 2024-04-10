#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 1234567891;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

vector <int> conn[200050];
bool dchk[200050];
int par[200050];
int color[200050];
set <int> Sx[200050];
void DFS(int n) {
	dchk[n] = true;

	Sx[n].insert(color[n]);
	if (n != 1) Sx[n].insert(color[par[n]]);

	int st = 1;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		while (Sx[n].count(st)) st++;
		Sx[n].insert(st);
		par[it] = n;
		color[it] = st;
		DFS(it);
	}
}
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	int ans = 1;
	for (i = 1; i <= N; i++) ans = max(ans, (int)conn[i].size() + 1);

	printf("%d\n", ans);
	color[1] = 1;
	DFS(1);
	for (i = 1; i <= N; i++) printf("%d ", color[i]);
	
	printf("\n");
}