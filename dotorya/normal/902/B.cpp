#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> son[10050];
int C[10050];
int cur[10050];
void DFS(int n, int c) {
	cur[n] = c;
	for (auto it : son[n]) DFS(it, c);
}

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 2; i <= N; i++) {
		scanf("%d", &j);
		son[j].push_back(i);
	}
	for (i = 1; i <= N; i++) scanf("%d", &C[i]);
	
	int ans = 0;
	for (i = 1; i <= N; i++) {
		if (cur[i] == C[i]) continue;
		ans++;
		DFS(i, C[i]);
	}
	return !printf("%d\n", ans);
}