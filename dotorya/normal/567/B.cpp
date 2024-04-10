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

set <int> S;
int in[105][2];
int main() {
	char c[2];
	int N, i;
	scanf("%d", &N);
	int t = 0, ans = 0;
	for (i = 1; i <= N; i++) {
		scanf("%s %d", c, &in[i][1]);
		if (c[0] == '-') {
			in[i][0] = 1;
			if (S.count(in[i][1]) == 0) t++;
		}
		S.insert(in[i][1]);
	}

	ans = t;
	for (i = 1; i <= N; i++) {
		if (in[i][0] == 0) t++;
		else t--;
		ans = max(ans, t);
	}
	printf("%d", ans);
	return 0;
}
//*/