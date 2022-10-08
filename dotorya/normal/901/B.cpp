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

vector <int> Vl[155];
int main() {
	Vl[0].push_back(1);
	Vl[1].push_back(0);
	Vl[1].push_back(1);

	int i, j;
	for (i = 2; i <= 150; i++) {
		Vl[i].push_back(0);
		for (auto it : Vl[i - 1]) Vl[i].push_back(it);

		for (j = 0; j < Vl[i - 2].size(); j++) Vl[i][j] += Vl[i - 2][j];
		for (j = 0; j < Vl[i].size(); j++) if (abs(Vl[i][j]) >= 2) break;
		if (j >= Vl[i].size()) continue;
		for (j = 0; j < Vl[i - 2].size(); j++) Vl[i][j] -= 2 * Vl[i - 2][j];
		for (j = 0; j < Vl[i].size(); j++) if (abs(Vl[i][j]) >= 2) break;
		if (j >= Vl[i].size()) continue;
	}

	int N;
	scanf("%d", &N);
	printf("%d\n", Vl[N].size()-1);
	for (auto it : Vl[N]) printf("%d ", it);
	printf("\n");
	printf("%d\n", Vl[N - 1].size()-1);
	for (auto it : Vl[N - 1]) printf("%d ", it);
	printf("\n");
	return 0;
}