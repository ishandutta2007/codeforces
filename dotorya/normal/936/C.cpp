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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char u[2][2050];
vector <int> Vp[2][26];

vector <int> Va;
int in[2050];
int N;
int uin[2050];
void myreverse(int x) {
	Va.push_back(x);
	for (int i = N - x; i < N; i++) uin[N - 1 - i] = in[i];
	for (int i = 0; i < N - x; i++) uin[i + x] = in[i];
	for (int i = 0; i < N; i++) in[i] = uin[i];
}

vector <int> Vl;
int main() {
	int i, j, k;
	scanf("%d", &N);
	scanf("%s %s", u[0], u[1]);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < N; j++) Vp[i][u[i][j] - 'a'].push_back(j);
	}

	for (i = 0; i < 26; i++) if (Vp[0][i].size() != Vp[1][i].size()) return !printf("-1\n");

	int c = 0;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < Vp[0][i].size(); j++) in[Vp[0][i][j]] = Vp[1][i][j];
	}

	for (i = 0; i < N-1-i; i++) {
		Vl.push_back(i);
		Vl.push_back(N - 1 - i);
	}
	if (N % 2) Vl.push_back(N / 2);

	reverse(all(Vl));

	for (i = 0; i < N; i++) {
		int p = 0;
		for (j = 0; j < N; j++) if (in[j] == Vl[i]) p = j;
		myreverse(N - p - 1);
		myreverse(1);
		myreverse(N - i - 1);
	}
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}