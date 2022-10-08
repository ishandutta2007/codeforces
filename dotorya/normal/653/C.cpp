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
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

int in[200000], N;
vector <int> V;

bool isValid(int x) {
	if (x % 2 == 1 && in[x] >= in[x + 1]) return false;
	if (x % 2 == 0 && in[x] <= in[x + 1]) return false;
	return true;
}
int canswap(int a, int b) {
	int rv = 1;
	
	swap(in[a], in[b]);
	if (a != 1 && !isValid(a - 1)) rv = 0;
	if (a != N && !isValid(a)) rv = 0;
	if (b != 1 && !isValid(b - 1)) rv = 0;
	if (b != N && !isValid(b)) rv = 0;
	for (auto it : V) if (!isValid(it)) rv = 0;

	swap(in[a], in[b]);
	return rv;
}
int main() {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i < N; i++) if (!isValid(i)) V.push_back(i);
	if (V.size() >= 5) return !printf("0\n");

	int t = V[0];
	int ans = 0;
	for (i = 1; i <= N; i++) ans += canswap(t, i);
	for (i = 1; i <= N; i++) ans += canswap(t + 1, i);
	ans -= canswap(t, t + 1);

	return !printf("%d\n", ans);
}
//*/