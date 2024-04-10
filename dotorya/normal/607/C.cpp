//*
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


#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

char in1[1000050];
char in2[1000050];
int ch[1024];

ll po31[1000050];
ll po43[1000050];
int main() {
	ch['N'] = 1;
	ch['S'] = 4;
	ch['E'] = 2;
	ch['W'] = 3;

	int N, i;
	ll h131 = 0, h143 = 0, h231 = 0, h243 = 0;
	scanf("%d", &N);
	scanf("%s %s", in1, in2);

	po31[0] = po43[0] = 1;
	for (i = 1; i <= N; i++) po31[i] = (po31[i - 1] * 31) % MOD;
	for (i = 1; i <= N; i++) po43[i] = (po43[i - 1] * 43) % MOD;
	for (i = N - 2; i >= 0; i--) {
		h131 = (h131 + po31[N - 2 - i] * ch[in1[i]]) % MOD;
		h143 = (h143 + po43[N - 2 - i] * ch[in1[i]]) % MOD;
		h231 = (h231 * 31 + 5 - ch[in2[i]]) % MOD;
		h243 = (h243 * 43 + 5 - ch[in2[i]]) % MOD;
		if (h131 == h231 && h143 == h243) return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
	
}