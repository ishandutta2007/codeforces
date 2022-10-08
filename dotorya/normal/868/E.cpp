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
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> conn[55];
int gpar[55];

int D[55][55];
int deg[55];
int u[55];

int cri[55];

int dp[55][55];
int main() {
	int N, S, M, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) if (i != j) D[i][j] = INF;
	for (i = 1; i < N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		D[t1][t2] = min(D[t1][t2], t3);
		D[t2][t1] = min(D[t2][t1], t3);
		deg[t1]++;
		deg[t2]++;
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	for (k = 1; k <= N; k++) for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) D[i][j] = min(D[i][k] + D[k][j], D[i][j]);

	int lc = 0;
	for (i = 1; i <= N; i++) if (deg[i] == 1) u[++lc] = i;

	scanf("%d", &S);
	scanf("%d", &M);
	for (i = 1; i <= M; i++) {
		int t;
		scanf("%d", &t);
		cri[t]++;
	}

	for (i = 1; i <= lc; i++) {
		for (j = 1; j <= lc; j++) dp[i][1] = max(dp[i][1], D[u[i]][u[j]]);
	}

	for (i = 2; i <= M; i++) {
		for (j = 1; j <= lc; j++) {
			int st = 1, en = INF, mi, rv = 0;
			while (st <= en) {
				mi = (st + en) / 2;
				int c = 0;
				for (k = 1; k <= lc; k++) {
					if (k == j) continue;
					for (l = 1; l <= i; l++) if (dp[k][i - l] + D[u[j]][u[k]] < mi) break;
					c += l - 1;
				}
				if (c >= i) {
					rv = mi;
					st = mi + 1;
				}
				else en = mi - 1;
			}
			dp[j][i] = rv;
		}
	}
	if (deg[S] == 1) {
		for (i = 1; i <= lc; i++) if (u[i] == S) break;
		return !printf("%d\n", dp[i][M]);
	}

	vector <int> Vu;
	gpar[S] = S;
	for (auto it : conn[S]) {
		gpar[it] = it;
		Vu.push_back(it);
		for (i = 0; i < Vu.size(); i++) {
			for (auto it2 : conn[Vu[i]]) {
				if (gpar[it2]) continue;
				gpar[it2] = it;
				Vu.push_back(it2);
			}
		}
		Vu.clear();
	}

	int st = 1, en = INF, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		bool c = false;
		for (auto it : conn[S]) {
			int cnt = 0;
			Vu.clear();
			for (i = 1; i <= lc; i++) if (gpar[u[i]] == it) Vu.push_back(i);
			for (i = 1; i <= N; i++) if (gpar[i] == it) cnt += cri[i];

			int cnt2 = 0;
			for (auto it : Vu) {
				for (i = 1; i <= cnt; i++) if (dp[it][M - i] + D[S][u[it]] < mi) break;
				cnt2 += i - 1;
			}
			if (cnt2 < cnt) {
				c = true;
				break;
			}
		}
		if (!c) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return !printf("%d\n", rv);
}