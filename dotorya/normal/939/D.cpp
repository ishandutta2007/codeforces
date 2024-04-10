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

int r[26];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

bool dchk[26];
char u1[100050];
char u2[100050];
vector <int> Vl[26];
int main() {
	int N, i;
	scanf("%d", &N);

	for (i = 0; i < 26; i++) r[i] = i;
	scanf("%s %s", u1, u2);
	for (i = 0; i < N; i++) {
		int t1 = u1[i] - 'a', t2 = u2[i] - 'a';
		if (t1 == t2) continue;
		r[root(t1)] = root(t2);
		dchk[t1] = dchk[t2] = true;
	}

	vector <pii> Va;
	for (i = 0; i < 26; i++) Vl[root(i)].push_back(i);
	for (i = 0; i < 26; i++) {
		if (Vl[i].empty()) continue;
		if (!dchk[Vl[i][0]]) continue;

		for (int j = 0; j + 1 < Vl[i].size(); j++) Va.emplace_back(Vl[i][j], Vl[i][j + 1]);
	}

	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%c %c\n", it.first + 'a', it.second + 'a');
	return 0;
}