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

int in[200050];

int sum[200050];

vector <int> Vl[200050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i <= N; i++) scanf("%d", &in[i]);

	for (i = 1; i < N; i++) if (in[i] > 1 && in[i + 1] > 1) break;
	if (i >= N) return !printf("perfect\n");

	int p = i;
	printf("ambiguous\n");
	sum[0] = 1;
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i];

	int st = 2;
	printf("0 ");
	Vl[0].push_back(1);
	for (i = 1; i <= N; i++) {
		for (j = st; j <= sum[i]; j++) {
			printf("%d ", Vl[i - 1][0]);
			Vl[i].push_back(j);
		}
		st = sum[i] + 1;
	}
	printf("\n");
	for (i = 0; i <= N; i++) Vl[i].clear();

	st = 2;
	printf("0 ");
	Vl[0].push_back(1);
	for (i = 1; i <= N; i++) {
		if (i != p+1) {
			for (j = st; j <= sum[i]; j++) {
				printf("%d ", Vl[i - 1][0]);
				Vl[i].push_back(j);
			}
		}
		else {
			printf("%d ", Vl[i - 1][1]);
			Vl[i].push_back(st);
			for (j = st + 1; j <= sum[i]; j++) {
				printf("%d ", Vl[i - 1][0]);
				Vl[i].push_back(j);
			}
		}
		st = sum[i] + 1;
	}
	return 0;
}