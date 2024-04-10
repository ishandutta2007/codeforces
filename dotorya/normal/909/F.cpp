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

int ans[100050];
void aa1(int x) {
	if (x == 2) {
		ans[1] = 2;
		ans[2] = 1;
		return;
	}

	int i;
	for (i = 2; i <= 30; i++) if ((1 << i) > x + 2) break;
	int v = i - 1;

	if (x + 2 == (1 << v)) {
		for (int i = 1; i <= x; i++) ans[i] = x + 1 - i;
		return;
	}

	int nx;
	for (i = (1 << v); i <= x; i++) {
		int t = (1 << (v + 1)) - 1 - i;
		ans[i] = t;
		ans[t] = i;
		nx = t;
	}
	aa1(nx - 1);
}
void aa2(int N) {
	int v = 1;
	while (v * 2 <= N) v *= 2;

	int i;
	for (i = 2; i < v; i += 2) {
		ans[i] = i + 1;
		ans[i + 1] = i;
	}

	vector <int> Vu;
	for (i = v; i <= N; i++) Vu.push_back(i);
	if (Vu.back() % 2 == 0) swap(Vu[Vu.size() - 2], Vu.back());

	ans[Vu.back()] = 1;
	ans[1] = Vu.back();
	Vu.pop_back();
	for (i = 0; i < Vu.size(); i++) ans[Vu[i]] = Vu[(i + 1) % Vu.size()];
}
int main() {
	int N;
	scanf("%d", &N);

	if (N % 2 == 1) printf("NO\n");
	else {
		printf("YES\n");
		aa1(N);
		for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
		printf("\n");
	}

	if (N <= 5) printf("NO\n");
	else {
		int t = 1;
		while (t * 2 <= N) t *= 2;
		if (t == N) return !printf("NO\n");
		if (t + 1 == N) {
			ans[N - 1] = N;
			ans[N] = N - 1;
			aa2(N - 2);
		}
		else aa2(N);

		printf("YES\n");
		for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}