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

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

bitset<4096> chk[100050];
int in[12][100050];
int main() {
	int N, K, Q, i, j;
	scanf("%d %d %d", &N, &K, &Q);
	for (i = 0; i < K; i++) for (j = 1; j <= N; j++) scanf("%d", &in[i][j]);

	int c = K;
	for (i = 1; i <= K; i++) for (j = 0; j < (1 << K); j++) chk[i][j] = !!(j & (1 << (i-1)));
	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) {
			c++;
			chk[c] = chk[t3] & chk[t2];
		}
		if(t1 == 2) {
			c++;
			chk[c] = chk[t3] | chk[t2];
		}
		if (t1 == 3) {
			int u[12];
			for (i = 0; i < K; i++) u[i] = i;
			sort(u, u + K, [&](int a, int b) {
				return in[a][t3] < in[b][t3];
			});

			int v = 0;
			for (i = 0; i < K; i++) {
				v |= 1 << u[i];
				if (chk[t2][v]) break;
			}
			printf("%d\n", in[u[i]][t3]);
		}
	}
	return 0;
}