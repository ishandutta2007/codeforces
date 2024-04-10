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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

bool dp[35][62][2201];
int rev[35][62][2201];
int in[35];

int ans[65][65];
bool tchk[65];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	sort(in + 1, in + N + 1);

	dp[0][0][0] = true;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 61; j++) {
			for (k = 0; k <= 2200; k++) {
				if (!dp[i - 1][j][k]) continue;
				for (l = 1;; l++) {
					int t1 = j + l, t2 = k + in[i] * l;
					if (t1 > 61 || t2 > 2200) break;
					if (t2 < t1 * (t1 - 1) / 2) continue;
					dp[i][t1][t2] = true;
					rev[i][t1][t2] = l;
				}
			}
		}
	}

	for (i = 1; i <= 61; i++) if (dp[N][i][i*(i - 1) / 2]) break;
	if (i > 61) return !printf("=(\n");

	int v1 = i, v2 = i * (i - 1) / 2;
	vector <int> Vx;
	for (i = N; i >= 1; i--) {
		int t = rev[i][v1][v2];
		for (j = 1; j <= t; j++) Vx.push_back(in[i]);
		v1 -= t, v2 -= in[i] * t;
	}

	N = Vx.size();
	printf("%d\n", N);
	for (i = 0; i < N; i++) {
		vector <int> Vu;
		for (j = 0; j < N; j++) if (!tchk[j]) Vu.push_back(j);
		sort(all(Vu), [&](int a, int b) {
			return Vx[a] > Vx[b];
		});
		for (j = 1; j <= (int)Vu.size() - 1 - Vx[Vu[0]]; j++) {
			ans[Vu[j]][Vu[0]] = 1;
			Vx[Vu[j]]--;
		}
		for (; j < Vu.size(); j++) ans[Vu[0]][Vu[j]] = 1;
		tchk[Vu[0]] = true;
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) printf("%d", ans[i][j]);
		printf("\n");
	}
	return 0;
}