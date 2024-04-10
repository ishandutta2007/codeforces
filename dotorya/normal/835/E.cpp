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

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

bool chk[10];
bool isOdd(vector <int>& Vu, int X) {
	if (Vu.empty()) return false;
	printf("? %d ", (int)Vu.size());
	for (auto it : Vu) printf("%d ", it + 1);
	printf("\n");
	fflush(stdout);

	int t;
	scanf("%d", &t);
	
	int v = 0;
	if (Vu.size() % 2) v = X;
	return t != v;
}
int main() {
	int N, X, Y, i, j;
	scanf("%d %d %d", &N, &X, &Y);
	for (i = 0; i < 10; i++) {
		vector <int> Vu;
		for (j = 0; j < N; j++) if (j & (1 << i)) Vu.push_back(j);
		chk[i] = isOdd(Vu, X);
	}
	
	int p = 0;
	for (i = 0; i < 10; i++) if (chk[i]) break;
	p = i;

	int a1 = 0, a2 = 1 << p;
	for (i = 0; i < 10; i++) {
		if (i == p) continue;

		vector <int> Vu;
		for (j = 0; j < N; j++) {
			if ((j & (1 << i)) && (j & (1 << p))) Vu.push_back(j);
		}
		bool tc = isOdd(Vu, X);

		if (tc) a2 += 1 << i;
		if (tc ^ chk[i]) a1 += 1 << i;
	}
	if (a1 > a2) swap(a1, a2);
	printf("! %d %d\n", a1 + 1, a2 + 1);
	fflush(stdout);
	return 0;
}