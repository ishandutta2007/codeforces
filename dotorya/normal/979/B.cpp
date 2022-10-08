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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

char u[100050];

int cnt[52];
int ch(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a';
	return c - 'A' + 26;
}
int getans(int N) {
	scanf("%s", u);
	int i, L = strlen(u);
	for (i = 0; i < 52; i++) cnt[i] = 0;
	for (i = 0; i < L; i++) cnt[ch(u[i])]++;

	if (L == 1) return 1;

	int mx = 0;
	for (i = 0; i < 52; i++) mx = max(mx, cnt[i]);

	if (mx == L) {
		if (N == 1) return mx - 1;
		else return mx;
	}

	return min(L, mx + N);
}
int main() {
	int N, i;
	scanf("%d", &N);

	int v[3];
	v[0] = getans(N);
	v[1] = getans(N);
	v[2] = getans(N);

	int mx = max(max(v[0], v[1]), v[2]);

	int c = 0;
	for (i = 0; i < 3; i++) if (v[i] == mx) c++;
	if (c >= 2) return !printf("Draw\n");

	if (v[0] == mx) printf("Kuro\n");
	if (v[1] == mx) printf("Shiro\n");
	if (v[2] == mx) printf("Katie\n");
	return 0;
}