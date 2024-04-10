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

int IT_MAX = 1 << 19;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll ocnt[140000];
ll cnt1[140000];
ll cnt2[140000];
ll cnt3[140000];
vector <ll> aa(vector <ll> Vx, vector<ll> Vy) {
	vector <ll> Vr;
	if (Vx.size() == 1) {
		Vr.push_back(Vx[0] * Vy[0]);
		return Vr;
	}
	
	vector <ll> Vu1;
	vector <ll> Vu2;
	vector <ll> Vu3;
	vector <ll> Vu4;
	int N = Vx.size(), i;

	for (i = 0; i < N / 2; i++) Vu1.push_back(Vx[i] + Vx[i + N / 2]);
	for (i = 0; i < N / 2; i++) Vu2.push_back(Vx[i] - Vx[i + N / 2]);
	for (i = 0; i < N / 2; i++) Vu3.push_back(Vy[i] + Vy[i + N / 2]);
	for (i = 0; i < N / 2; i++) Vu4.push_back(Vy[i] - Vy[i + N / 2]);

	vector <ll> Vr1 = aa(Vu1, Vu3);
	vector <ll> Vr2 = aa(Vu2, Vu4);

	for (i = 0; i < N / 2; i++) Vr.push_back((Vr1[i] + Vr2[i]) / 2);
	for (i = 0; i < N / 2; i++) Vr.push_back((Vr1[i] - Vr2[i]) / 2);
	return Vr;
}

ll u1[140000];
ll u2[140000];
ll u3[140000];

ll dp[131072];
ll tdp[131072];
ll F[131072];
void ch(ll* cnt, ll* u) {
	int M = 131072, i, j;
	for (i = 0; i < M; i++) dp[i] = F[i] * (cnt[i] % MOD) % MOD;
	
	for (i = 0; i < 17; i++) {
		for (j = 0; j < M; j++) if (!(j & (1 << i))) dp[j] += dp[j^(1<<i)];
	}
	for (i = 0; i < M; i++) u[i] = dp[i] % MOD;
}
int pop1[131072];


int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		ocnt[t]++;
	}
	F[0] = 0, F[1] = 1;
	for (i = 2; i < 131072; i++) F[i] = (F[i - 1] + F[i - 2]) % MOD;

	int M = 131072;
	for (i = 0; i < M; i++) {
		int t = (M - 1) ^ i;
		for (j = t; j >= 0; j = (j - 1)&t) {
			cnt1[i | j] += ocnt[i] * ocnt[j];
			if (j == 0) break;
		}
	}
	for (i = 0; i < M; i++) cnt2[i] = ocnt[i];

	vector <ll> Vu1;
	vector <ll> Vu2;
	for (i = 0; i < M; i++) {
		Vu1.push_back(ocnt[i]);
		Vu2.push_back(ocnt[i]);
	}
	vector <ll> Vu3 = aa(Vu1, Vu2);
	for (i = 0; i < M; i++) cnt3[i] = Vu3[i];

	ch(cnt1, u1);
	ch(cnt2, u2);
	ch(cnt3, u3);

	for (i = 0; i < M; i++) for (j = 0; j < 17; j++) if (i & (1 << j)) pop1[i]++;

	ll ans = 0;
	for (i = 0; i < 17; i++) {
		int t = (M - 1) ^ (1 << i);
		for (j = t; j >= 0; j = (j - 1) & t) {
			int tx = j | (1 << i);
			ll v = 1;
			v = (v * u1[tx]) % MOD;
			v = (v * u2[tx]) % MOD;
			v = (v * u3[tx]) % MOD;
			if (pop1[j] % 2 == 0) ans = (ans + v) % MOD;
			else ans = (ans - v + MOD) % MOD;
			if (j == 0) break;
		}
	}
	return !printf("%lld\n", ans);
}
//*/