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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> Vl = { 2,3,5,7,11,13,17,19,23,29,31 };
vector <int> Vl2 = { 37,41,43,47,53,59,61,67 };
int cnt[10];

ll dp[2048];
ll tdp[2048];
int main() {
	int N, i, j, k;
	scanf("%d", &N);

	dp[0] = 1;
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		for (j = 0; j < Vl2.size(); j++) {
			if (Vl2[j] == t) break;
		}
		if (j < Vl2.size()) {
			cnt[j]++;
			continue;
		}
		
		int t2 = 0;
		for (j = 0; j < 11; j++) {
			int c = 0;
			while (t % Vl[j] == 0) {
				c++;
				t /= Vl[j];
			}
			if (c % 2) t2 |= (1 << j);
		}
		for (j = 0; j < 2048; j++) tdp[j] = (dp[j] + dp[j^t2]) % MOD;
		for (j = 0; j < 2048; j++) dp[j] = tdp[j];
	}
	
	ll ans = dp[0];
	for (i = 0; i < Vl2.size(); i++) for (j = 1; j <= cnt[i] - 1; j++) ans = ans * 2 % MOD;
	return !printf("%lld\n", (ans+MOD-1)%MOD);
}