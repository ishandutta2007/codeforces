//*
#include <algorithm>
#include <ctype.h>
#include <functional>
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

const int IT_MAX = 1048576;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

int in[100050];
int main() {
	int N, K, i, j, t;
	scanf("%d %d", &N, &K);

	int ans = N - 1;
	for (i = 1; i <= K; i++) {
		scanf("%d", &t);
		ans += t - 1;
		scanf("%d", &in[1]);
		bool chk = false;
		if (in[1] == 1) chk = true;
		for (j = 2; j <= t; j++) {
			scanf("%d", &in[j]);
			if (in[j] - in[j - 1] != 1) chk = false;
			if (chk) ans -= 2;
		}
	}
	printf("%d", ans);
	return 0;
}
//*/