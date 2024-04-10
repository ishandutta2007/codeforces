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

int IT_MAX = 1 << 20;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

int lr[3][2];
char u[100050];
int main() {
	scanf("%s", u);

	int i, j;
	for (i = 0; i < 3; i++) lr[i][0] = INF, lr[i][1] = -1;
	for (i = 0; u[i] != 0; i++) {
		int t = u[i] - 'a';
		lr[t][0] = min(lr[t][0], i);
		lr[t][1] = max(lr[t][1], i);
	}

	if (lr[0][0] == INF || lr[1][0] == INF || lr[2][0] == INF) return !printf("NO\n");
	if (lr[0][1] >= lr[1][0] || lr[1][1] >= lr[2][0]) return !printf("NO\n");
	if (lr[0][1] - lr[0][0] != lr[2][1] - lr[2][0] && lr[1][1] - lr[1][0] != lr[2][1] - lr[2][0]) return !printf("NO\n");
	return !printf("YES\n");
}