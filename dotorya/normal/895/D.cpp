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

char in1[1000050];
char in2[1000050];
int ocnt[26];
int cnt[26];

ll F[2000050];
ll Finv[2000050];
ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}

ll getans() {
	int s = 0;
	ll rv = 1;
	for (int i = 0; i < 26; i++) {
		s += cnt[i];
		rv = rv * Finv[cnt[i]] % MOD;
	}
	rv = rv * F[s] % MOD;
	return rv;
}

int main() {
	int L, i, j;
	scanf("%s %s", in1, in2);
	L = strlen(in1);
	for (i = 0; i < L; i++) if (in1[i] != in2[i]) break;
	int x = i;
	for (i = x; i < L; i++) in1[i - x] = in1[i];
	for (i = x; i < L; i++) in2[i - x] = in2[i];
	L -= x;
	in1[L] = in2[L] = 0;

	F[0] = 1;
	for (i = 1; i <= 2000000; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= 2000000; i++) Finv[i] = mul_inv(F[i]);

	for (i = 0; i < L; i++) cnt[in1[i] - 'a']++;

	ll ans = 0;
	for (i = 0; i < 26; i++) ocnt[i] = cnt[i];
	for (i = in1[0] - 'a' + 1; i <= in2[0] - 'a' - 1; i++) {
		if (!cnt[i]) continue;
		cnt[i]--;
		ans += getans();
		cnt[i]++;
	}
	for (i = 0; i + 1 < L; i++) {
		cnt[in1[i]-'a']--;

		ll s = 0;
		ll v = 1;
		for (j = 0; j < 26; j++) {
			s += cnt[j];
			v = v * Finv[cnt[j]] % MOD;
		}
		v = v * F[s-1] % MOD;
		for (j = in1[i+1]-'a'+1; j < 26; j++) {
			if (!cnt[j]) continue;
			ans += v * cnt[j] % MOD;
		}
	}
	for (i = 0; i < 26; i++) cnt[i] = ocnt[i];
	for (i = 0; i + 1 < L; i++) {
		if (cnt[in2[i] - 'a']-- == 0) break;
		
		ll s = 0;
		ll v = 1;
		for (j = 0; j < 26; j++) {
			s += cnt[j];
			v = v * Finv[cnt[j]] % MOD;
		}
		v = v * F[s - 1] % MOD;
		for (j = 0; j < in2[i+1] - 'a'; j++) {
			if (!cnt[j]) continue;
			ans += v * cnt[j] % MOD;
		}
	}
	return !printf("%lld\n", ans%MOD);
}