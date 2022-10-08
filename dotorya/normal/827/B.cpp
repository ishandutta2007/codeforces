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

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);

	int x = (N - 1) / M, y = (N - 1) - M * x;

	int d = 2 * x;
	if (y == 1) d = 2 * x + 1;
	if (y >= 2) d = 2 * x + 2;

	printf("%d\n", d);
	int p = 1;
	for (i = 1; i <= M; i++) {
		int st = N;
		int c = x;
		if (i <= y) c++;

		for (j = 1; j <= c; j++) {
			printf("%d %d\n", st, p);
			st = p;
			p++;
		}
	}
	return 0;
}