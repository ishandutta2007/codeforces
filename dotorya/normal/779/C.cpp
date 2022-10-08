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
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

pii in[300050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i].first);
	for (i = 1; i <= N; i++) scanf("%d", &in[i].second);
	
	sort(in + 1, in + N + 1, [](pii a, pii b) {
		return a.second - a.first > b.second - b.first;
	});
	
	int ans = 0;
	for (i = 1; i <= K; i++) ans += in[i].first;
	for (i = K + 1; i <= N; i++) ans += min(in[i].first, in[i].second);
	return !printf("%d\n", ans);
}