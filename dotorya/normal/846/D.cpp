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

int in[250050][3];

int sum[505][505];
int main() {
	int N, M, K, Q, i, j, k;
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for (i = 1; i <= Q; i++) for (j = 0; j < 3; j++) scanf("%d", &in[i][j]);

	int st = 0, en = INF, mi, rv = INF + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		for (i = 1; i <= Q; i++) if (in[i][2] <= mi) sum[in[i][0]][in[i][1]] = 1;
		for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		for (i = 1; i + K - 1 <= N; i++) {
			for (j = 1; j + K - 1 <= M; j++) {
				int s = sum[i + K - 1][j + K - 1] - sum[i - 1][j + K - 1] - sum[i + K - 1][j - 1] + sum[i - 1][j - 1];
				if (s == K*K) break;
			}
			if (j + K - 1 <= M) break;
		}
		if (i + K - 1 <= N) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
		memset(sum, 0, sizeof(sum));
	}
	if (rv == INF + 1) rv = -1;
	return !printf("%d\n", rv);
}