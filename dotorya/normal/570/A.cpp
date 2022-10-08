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

const int MOD = 9999991;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int tcnt[105];
int cnt[105];

int main() {
	int N, M, i, j, t;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int mx = 1;
		for (j = 1; j <= N; j++) {
			scanf("%d", &cnt[j]);
			if (cnt[j] > cnt[mx]) mx = j;
		}
		tcnt[mx]++;
	}

	int ans = 1;
	for (i = 2; i <= N; i++) if (tcnt[i] > tcnt[ans]) ans = i;
	printf("%d", ans);
	return 0;
}
//*/