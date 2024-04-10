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

char in[10][10];
int main() {
	int i, j, k;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j += 3) scanf("%s", in[i] + j);
	}
	int t1, t2;
	scanf("%d %d", &t1, &t2);
	t1--, t2--;

	int x = t1 % 3, y = t2 % 3;
	bool chk = false;
	for (i = x * 3; i < (x + 1) * 3; i++) {
		for (j = y * 3; j < (y + 1) * 3; j++) {
			if (in[i][j] == '.') {
				chk = true;
				in[i][j] = '!';
			}
		}
	}
	if (!chk) for (i = 0; i < 9; i++) for (j = 0; j < 9; j++) if (in[i][j] == '.') in[i][j] = '!';

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%c", in[i][j]);
			if (j == 2 || j == 5) printf(" ");
			if (j == 8) printf("\n");
		}
		if (i == 2 || i == 5 || i == 8) printf("\n");
	}
	return 0;
}