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
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX;
const int MOD = 9901;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

char in[100050];
int v[100050];
int v2[100050];
int v3[100050];
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	scanf("%s", &in[1]);

	v[N] = 1;
	for (i = N - 1; i >= 1; i--) {
		v[i] = v[i + 1];
		if (in[i] != in[i + 1]) v[i]++;
	}
	
	v3[N] = 1;
	for (i = N - 1; i >= 1; i--) {
		if (in[i] == in[i + 1]) v3[i] = v3[i + 1] + 1;
		else v3[i] = 1;
	}

	v2[N - 1] = 2;
	for (i = N - 2; i >= 1; i--) {
		if (in[i] == in[i + 2]) v2[i] = v2[i + 1] + 1;
		else if (in[i + 1] == in[i + 2]) v2[i] = v3[i]+1;
		else v2[i] = 2;
	}

	ll ans = M - 1;
	for (i = N - 1; i >= 1; i--) {
		ll t = M - 1;
		if (in[i] == in[i + 1]) {
			ans += t*v[i];
			continue;
		}

		ans += (N - i)*(M - 1) + 1 + t*v[i] - v2[i];
		
	}
	printf("%lld", ans);
	return 0;
}
//*/