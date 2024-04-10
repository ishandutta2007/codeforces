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

map <int, int> M;
int in[200050];
int cnt[600050];
int cnt2[600050];
int main() {
	int N, K, i;
	ll ans = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		M.insert(pii(in[i], 0));
		if (in[i] % K == 0) M.insert(pii(in[i] / K, 0));
		if (abs(in[i]) <= INF / K) M.insert(pii(in[i] * K, 0));
	}
	
	i = 0;
	for (auto it = M.begin(); it != M.end(); it++) it->second = ++i;

	for (i = 1; i <= N; i++) cnt[M[in[i]]]++;
	for (i = 1; i <= N; i++) {
		cnt[M[in[i]]]--;
		if (in[i] % K == 0 && abs(in[i]) <= INF / K) {
			ans += (ll)cnt2[M[in[i] / K]] * cnt[M[in[i] * K]];
		}
		cnt2[M[in[i]]]++;
	}
	printf("%I64d", ans);
	return 0;
}
//*/