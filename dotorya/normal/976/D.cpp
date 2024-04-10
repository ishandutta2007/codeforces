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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int in[305];

bool chk[1050][1050];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int X = in[N] + 1;

	int st = 1, en = in[N] + 1;
	int sti = 1, eni = N;
	while (1) {
		if (sti == eni) {
			for (i = st; i <= en; i++) for (j = i + 1; j <= en; j++) chk[i][j] = true;
			break;
		}
		if (sti + 1 == eni) {
			for (i = st; i < st + in[sti]; i++) for (j = st; j <= en; j++) chk[i][j] = true;
			break;
		}
		
		for (i = sti + 1; i <= eni - 1; i++) in[i] -= in[sti];

		for (i = st; i < st + in[sti]; i++) for (j = st; j <= en; j++) chk[i][j] = true;
		st = st + in[sti];
		en = st + in[eni - 1];
		sti++, eni--;
	}
	
	vector <pii> Va;
	for (i = 1; i <= X; i++) for (j = i + 1; j <= X; j++) if (chk[i][j] || chk[j][i]) Va.emplace_back(i, j);

	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d %d\n", it.first, it.second);
}