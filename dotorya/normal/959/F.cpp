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
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll po2[200050];

vector <pii> Vq[100050];

int cur[20];

int in[100050];

ll ans[100050];
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 1; i <= Q; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Vq[t1].emplace_back(t2, i);
	}
	
	po2[0] = 1;
	for (i = 1; i <= 200000; i++) po2[i] = po2[i - 1] * 2 % MOD;

	for (i = 1; i <= N; i++) {
		int t = in[i];
		for (j = 19; j >= 0; j--) {
			if (!(t & (1 << j))) continue;
			if (cur[j]) t ^= cur[j];
			else {
				cur[j] = t;
				break;
			}
		}
		for (auto it : Vq[i]) {
			int v = it.first;
			for (j = 19; j >= 0; j--) {
				if (!(v & (1 << j))) continue;
				if (cur[j]) v ^= cur[j];
				else break;
			}
			if (j >= 0) ans[it.second] = 0;
			else {
				int cc = 0;
				for (j = 19; j >= 0; j--) if (cur[j]) cc++;
				ans[it.second] = po2[i - cc];
			}
		}
	}
	for (i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
	return 0;
}