//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <char, int> pci;

const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

set <pii> S;
bool chk[200050];
int main() {
	int N, K, A, T, i, t;
	scanf("%d %d %d", &N, &K, &A);
	scanf("%d", &T);
	int cnt = (N+1) / (A+1);
	S.insert(pii(1, N+1));
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &t);
		if (chk[t]) continue;
		chk[t] = true;
		auto it = S.lower_bound(pii(t + 1, 0));
		it--;
		int t1 = it->first, t2 = it->second;
		cnt -= (t2 - t1+1) / (A+1);
		S.erase(it);
		if (t1 != t) {
			S.insert(pii(t1, t));
			cnt += (t - t1+1) / (A+1);
		}
		if (t2 != t + 1) {
			S.insert(pii(t + 1, t2));
			cnt += (t2 - t) / (A+1);
		}
		if (cnt < K) return printf("%d", tc), 0;
	}
	return printf("-1"), 0;
}
//*/