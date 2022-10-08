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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

char in[105][105];
char u[105][105];
bool isValid(int N, int M) {
	if (N % 3) return false;

	char x[4] = "BGR";
	do {
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) u[i][j] = x[i / (N / 3)];
		
		int i, j;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) if (in[i][j] != u[i][j]) break;
			if (j < M) break;
		}
		if (i >= N) return true;
	} while (next_permutation(x, x + 3));
	return false;
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", in[i]);

	if (isValid(N, M)) return !printf("YES\n");
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) u[j][i] = in[i][j];
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) in[j][i] = u[j][i];
	if (isValid(M, N)) return !printf("YES\n");
	return !printf("NO\n");
}