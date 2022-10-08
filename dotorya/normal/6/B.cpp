#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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

int IT_MAX = 1 << 21;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char in[105][105];
int main() {
	char c[2];
	int N, M, i, j, k;
	scanf("%d %d %s", &N, &M, c);
	for (i = 0; i < N; i++) scanf("%s", in[i]);

	set <char> Sx;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (in[i][j] != c[0]) continue;
			for (k = 0; k < 4; k++) {
				int x = i + "1102"[k] - '1';
				int y = j + "0211"[k] - '1';
				if (x < 0 || x >= N || y < 0 || y >= M) continue;
				if (in[x][y] == '.' || in[x][y] == c[0]) continue;
				Sx.insert(in[x][y]);
			}
		}
	}
	return !printf("%d\n", (int)Sx.size());
}