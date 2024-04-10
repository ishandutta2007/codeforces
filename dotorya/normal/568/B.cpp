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
typedef pair <db, db> pdd;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

bool prime_chk[10000050];
int palinsum[10000050];
bool palinchk[10000050];
int primesum[10000050];

ll dpsum[4050];
ll comb[4050][4050];
ll po2[4050];

ll dp2[4050];
int main() {
	int i, j, N;

	for (i = 1; i <= 4000; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}

	dp2[0] = 1;
	dp2[1] = 0;
	for (i = 2; i <= 4000; i++) {
		for (j = i - 2; j >= 0; j--) dp2[i] = (dp2[i] + dp2[j]*comb[i-1][i-j-1])%MOD;
	}
	po2[0] = 1;
	for (i = 1; i <= 4000; i++) po2[i] = (po2[i - 1] * 2) % MOD;

	ll ans = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		ll t = (dp2[N - i] * comb[N][i]) % MOD;
		t = (t*(po2[i] - 1)) % MOD;
		ans = (ans + t) % MOD;
	}
	printf("%I64d", ans);
	return 0;
}
//*/