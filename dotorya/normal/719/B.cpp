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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char in1[100050];
char in2[100050];

int getans(int N) {
	int c1 = 0, c2 = 0;
	for (int i = 0; i < N; i++) {
		if (in1[i] == in2[i]) continue;
		if (in1[i] == 'r') c1++;
		else c2++;
	}
	return max(c1, c2);
}
int main() {
	int N, i;
	scanf("%d %s", &N, in1);
	for (i = 0; i < N; i++) {
		if(i%2) in2[i] = 'r';
		else in2[i] = 'b';
	}

	int ans = getans(N);
	for (i = 0; i < N; i++) {
		if (i % 2) in2[i] = 'b';
		else in2[i] = 'r';
	}
	ans = min(ans, getans(N));
	return !printf("%d\n", ans);
}