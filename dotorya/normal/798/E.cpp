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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

pii operator + (pii a, pii b) {
	return pii(a.first + b.first, a.second + b.second);
}
pii indt[1100000];
void update(int p, pii v) {
	p += IT_MAX - 1;
	indt[p] = indt[p] + v;
	for (p /= 2; p; p /= 2) indt[p] = max(indt[2 * p], indt[2 * p + 1]);
}
pii getmx(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	
	pii rv = pii(-2 * INF, -INF);
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

int N;
int A[500050];
int B[500050];

int ans[500050];
bool dchk[500050];
vector <int> Vu;
void DFS(int n) {
	update(n, pii(-INF * 2, 0));
	dchk[n] = true;
	while (1) {
		if (A[n] != N + 1 && !dchk[A[n]]) {
			DFS(A[n]);
			continue;
		}

		pii rv = getmx(1, B[n] - 1);
		if (rv.first <= n) break;
		DFS(rv.second);
	}
	Vu.push_back(n);
}
int main() {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) B[i] = N + 1;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if (A[i] == -1) A[i] = N + 1;
		else B[A[i]] = i;
	}
	for (i = 1; i <= N; i++) update(i, pii(A[i], i));

	int v = N;
	for (i = 1; i <= N; i++) {
		if (dchk[i]) continue;
		DFS(i);
		for (auto it : Vu) ans[it] = v--;
		Vu.clear();
	}
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}