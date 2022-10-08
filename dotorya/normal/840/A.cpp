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
#pragma comment(linker, "/STACK:33554432")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int in1[200050];
int in2[200050];
int u[200050];
int ans[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in1[i]);
	for (i = 1; i <= N; i++) scanf("%d", &in2[i]);
	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in2[a] < in2[b];
	});
	sort(in1 + 1, in1 + N + 1);
	for (i = 1; i <= N; i++) ans[u[i]] = in1[N + 1 - i];
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}