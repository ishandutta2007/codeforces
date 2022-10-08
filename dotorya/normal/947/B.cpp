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

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

multiset <ll> Sx;
ll off = 0;
ll in1[100050];
ll in2[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in1[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &in2[i]);

	for (i = 1; i <= N; i++) {
		Sx.insert(in1[i] + off);
		
		ll ans = 0;
		while (!Sx.empty()) {
			auto it = Sx.begin();
			if (*it - off > in2[i]) break;
			ans += *it - off;
			Sx.erase(it);
		}
		ans += (ll)Sx.size() * in2[i];
		off += in2[i];
		printf("%lld ", ans);
	}
	return !printf("\n");
}