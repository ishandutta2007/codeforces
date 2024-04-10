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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll L, R;

int cnt[15];
int ocnt[15];
ll po10[19];
int ans = 0;

ll vl[19];
int dl;

ll getmn() {
	int i, j;
	ll rv = 0;
	for (i = 1; i <= 9; i++) for (j = 1; j <= cnt[i]; j++) rv = rv * 10 + i;
	return rv;
}
void aa(int lvl, int s) {
	if (lvl) {
		for (int i = 0; i <= s; i++) {
			cnt[lvl] = i;
			aa(lvl - 1, s - i);
		}
		return;
	}

	if (s == 18) return;

	int i, j;
	for (i = 1; i <= 9; i++) ocnt[i] = cnt[i];

	int d = 18 - s;
	cnt[0] = s;
	if (d > dl) {
		ll v = getmn();
		if (v <= R) ans++;
		return;
	}

	if (cnt[1] == 0 && cnt[2] == 2) {
		cnt[1] = cnt[1];
	}
	ll cv = 0;
	for (i = 17; i >= 0; i--) {
		for (j = vl[i] + 1; j < 10; j++) if (cnt[j]) break;
		if (j < 10) {
			cnt[j]--;
			ll v = getmn();
			if (cv + po10[i] * j + v <= R) {
				{
					//					for (int i = 0; i < 10; i++) printf("%d ", ocnt[i]);
					//					printf("\n");
					ans++;
				}
				break;
			}
			cnt[j]++;
		}
		if (!cnt[vl[i]]) break;
		cnt[vl[i]]--;
		cv += vl[i] * po10[i];
	}
	if (i == -1) {
		//		for (int i = 0; i < 10; i++) printf("%d ", ocnt[i]);
		//		printf("\n");
		ans++;
	}

	for (i = 1; i <= 9; i++) cnt[i] = ocnt[i];
}
int main() {
	po10[0] = 1;
	for (int i = 1; i <= 18; i++) po10[i] = po10[i - 1] * 10;
	scanf("%lld %lld", &L, &R);
	if (R == po10[18]) {
		if (L == po10[18]) return !printf("1\n");
		if (L > po10[17]) ans++;
		R--;
	}

	ll t = L, i;
	for (i = 0; i <= 18; i++, t /= 10) vl[i] = t % 10;
	for (dl = 19; dl >= 1; dl--) if (vl[dl - 1]) break;
	aa(9, 18);
	return !printf("%d\n", ans);
}