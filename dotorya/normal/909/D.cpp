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

int N;
char in[1000050];
int lr[1000050][2];
set <int> Sx;
vector <int> Vl;
void update(int p) {
	if (p == 0 || p == N + 1) return;
	if (Sx.count(p)) Sx.erase(p);
	if (lr[p][0] != 0 && in[p] != in[lr[p][0]]) Sx.insert(p);
	if (lr[p][1] != N + 1 && in[p] != in[lr[p][1]]) Sx.insert(p);
}
int main() {
	scanf("%s", in + 1);
	N = strlen(in + 1);
	int i, j;
	for (i = 1; i <= N; i++) {
		if (i != 1 && in[i] != in[i - 1]) Sx.insert(i);
		if (i != N && in[i] != in[i + 1]) Sx.insert(i);
		lr[i][0] = i - 1, lr[i][1] = i + 1;
	}

	for (i = 0;; i++) {
		if (Sx.empty()) return !printf("%d\n", i);
		Vl.clear();
		for (auto it : Sx) Vl.push_back(it);
		for (auto it : Vl) {
			int t1 = lr[it][0], t2 = lr[it][1];
			lr[t1][1] = t2;
			lr[t2][0] = t1;
			update(t1);
			update(t2);
			Sx.erase(it);
		}
	}
	return 0;
}