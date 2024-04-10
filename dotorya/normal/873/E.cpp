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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int u[3050];
int oin[3050];
int ch[5050];
int in[5050];

vector <pii> Vu[5050];
int val[5050];
int mx[5050][5050];
int sum[5050];
int rsum[5050];

int ans[5050];


int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &oin[i]);
	for (i = 1; i <= N; i++) ch[i] = i;
	sort(ch + 1, ch + N + 1, [](int a, int b) {
		return oin[a] < oin[b];
	});
	for (i = 1; i <= N; i++) in[i] = oin[ch[i]];

	int X = N;
	for (i = 0; i < X; i++) val[i] = in[i + 1] - in[i];
	for (i = 0; i < X; i++) {
		mx[i][i] = i;
		for (j = i + 1; j < X; j++) {
			mx[i][j] = mx[i][j - 1];
			if (val[j] > val[mx[i][j]]) mx[i][j] = j;
		}
	}
	for (i = 1; i <= X; i++) sum[i] = sum[i - 1] + 1;
	for (i = 1; i <= X; i++) for (j = sum[i - 1] + 1; j <= sum[i]; j++) rsum[j] = i;
	rsum[sum[X] + 1] = X + 1;

	int mx1 = -1, mx2 = -1, mx3 = -1;
	int a1 = -1, a2 = -1, a3 = -1;
	for (i = X; i >= 1; i--) {
		for (j = i - 1; j >= 2; j--) {
			int c1 = sum[X] - sum[i - 1], c2 = sum[i - 1] - sum[j - 1];
			if (c1 * 2 < c2 || c2 * 2 < c1) continue;

			int st = 0, en = INF;
			st = max(st, (c1 + 1) / 2);
			st = max(st, (c2 + 1) / 2);
			en = min(en, c1 * 2);
			en = min(en, c2 * 2);
			en = min(en, sum[j - 1]);
			if (st > en) continue;

			int st2 = sum[j - 1] - en, en2 = sum[j - 1] - st;
			int st3 = rsum[st2], en3 = rsum[en2 + 1] - 1;
			if (st3 > en3) continue;
			k = mx[st3][en3];
			
			int m1 = val[i - 1], m2 = val[j - 1], m3 = val[k];
			if (mp(mx1, pii(mx2, mx3)) < mp(m1, pii(m2, m3))) {
				a1 = i;
				a2 = j;
				a3 = k + 1;
				mx1 = m1;
				mx2 = m2;
				mx3 = m3;
			}
		}
	}
	for (i = a1; i <= X; i++) ans[ch[i]] = 1;
	for (i = a2; i < a1; i++) ans[ch[i]] = 2;
	for (i = a3; i < a2; i++) ans[ch[i]] = 3;
	for (i = 1; i < a3; i++) ans[ch[i]] = -1;

	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}