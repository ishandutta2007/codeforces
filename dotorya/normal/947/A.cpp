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

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

vector <int> Vl[1000050];
vector <int> pl;
bool pchk[1000050];
int main() {
	int i, j;
	for (i = 2; i <= 1000000; i++) {
		if (pchk[i]) continue;
		pl.push_back(i);
		for (j = 2 * i; j <= 1000000; j+=i) pchk[j] = true;
		for (j = i; j <= 1000000; j+=i) Vl[j].push_back(i);
	}

	int x;
	scanf("%d", &x);
	
	int st = x - Vl[x].back() + 1, en = x;
	int ans = en;
	for (i = st; i <= en; i++) if(pchk[i]) ans = min(ans, i - Vl[i].back() + 1);
	ans = max(ans, 3);
	return !printf("%d\n", ans);
}