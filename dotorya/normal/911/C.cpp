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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int in[5];
int main() {
	scanf("%d %d %d", &in[1], &in[2], &in[3]);
	sort(in + 1, in + 4);

	if (in[1] >= 4) return !printf("NO\n");
	if (in[1] == 3) {
		if (in[2] == 3 && in[3] == 3) return !printf("YES\n");
		return !printf("NO\n");
	}
	if (in[1] == 2) {
		if (in[2] == 2) printf("YES\n");
		else if (in[2] >= 5) printf("NO\n");
		else if (in[2] == 4) {
			if (in[3] == 4) printf("YES\n");
			else printf("NO\n");
		}
		else if (in[2] == 3) {
			printf("NO\n");
		}
		return 0;
	}
	if (in[1] == 1) printf("YES\n");
	return 0;
}