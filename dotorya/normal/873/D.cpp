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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

void aa(int st, int en, int S, int E, int c) {
	if (c == 1) {
		for (int i = S; i <= E; i++) printf("%d ", i);
		return;
	}

	int mi = (st + en) / 2;
	int c1 = mi - st, c2 = en - mi;
	int v1 = min(c - 2, 2 * c1 - 1);
	int v2 = c - 1 - v1;
	int M = S + c2 - 1;
	aa(st, mi, M+1, E, v1);
	aa(mi, en, S, M, v2);
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	if (M % 2 == 0 || M > 2 * N - 1) return !printf("-1\n");

	aa(0, N, 1, N, M);
	printf("\n");
}