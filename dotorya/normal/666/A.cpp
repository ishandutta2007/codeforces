#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 2034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-16;

set <string> Sx;
char in[10050];
bool dp[10050][4];
int main() {
	scanf("%s", in);
	int L = strlen(in), i;

	if (L <= 6) return !printf("0\n");

	for (i = L - 1; i >= 5; i--) {
		if (i + 2 == L) {
			dp[i][2] = true;
			Sx.insert(string(in + i, in + L));
		}
		if (i + 3 == L) {
			dp[i][3] = true;
			Sx.insert(string(in + i, in + L));
		}

		if (i + 2 < L) {
			if (dp[i + 2][3] || (dp[i + 2][2] && string(in + i, in + i + 2) != string(in + i + 2, in + i + 4))) {
				dp[i][2] = true;
				Sx.insert(string(in + i, in + i + 2));
			}
		}
		if (i + 3 < L) {
			if (dp[i + 3][2] || (dp[i + 3][3] && string(in + i, in + i + 3) != string(in + i + 3, in + i + 6))) {
				dp[i][3] = true;
				Sx.insert(string(in + i, in + i + 3));
			}
		}
	}

	printf("%d\n", (int)Sx.size());
	for (auto it : Sx) printf("%s\n", it.c_str());
	return 0;
}