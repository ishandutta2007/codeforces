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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int ch[200050];
int in[200050];
int dp[200050][20];
int pos[200050];

vector <int> Vl[200050];

int indt[600000];
int getmn(int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;

	int rv = INF;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = min(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = min(rv, indt[p2--]);
	}
	return rv;
}
int main() {
	int N, M, Q, i, j;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		t--;
		ch[t] = i;
	}
	for (i = 0; i < M; i++) {
		scanf("%d", &in[i]);
		in[i]--;
		in[i] = ch[in[i]];
		Vl[in[i]].push_back(i);
	}

	for (i = M - 1; i >= 0; i--) {
		dp[i][0] = i;
		for (j = 1; j < 20; j++) {
			int p = dp[i][j - 1];
			if (p >= M) {
				dp[i][j] = M;
				continue;
			}

			int x = (in[i] + (1 << (j - 1))) % N;
			
			int y = lower_bound(all(Vl[x]), p + 1) - Vl[x].begin();
			if (y >= Vl[x].size()) dp[i][j] = M;
			else dp[i][j] = dp[Vl[x][y]][j - 1];
		}

		pos[i] = i - 1;
		int cur = in[i];
		for (j = 19; j >= 0; j--) {
			if (!(N & (1 << j))) continue;

			int x = lower_bound(all(Vl[cur]), pos[i] + 1) - Vl[cur].begin();
			if (x >= Vl[cur].size()) {
				pos[i] = M;
				break;
			}
			pos[i] = dp[Vl[cur][x]][j];
			cur = (cur + (1 << j)) % N;
			
			if (pos[i] >= M) break;
		}
	}
	for (i = 0; i < M; i++) indt[i + IT_MAX] = pos[i];
	for (i = IT_MAX - 1; i >= 1; i--) indt[i] = min(indt[2 * i], indt[2 * i + 1]);


	while (Q--) {
		int st, en;
		scanf("%d %d", &st, &en);
		st--, en--;

		if (getmn(st, en) <= en) printf("1");
		else printf("0");
	}
	return !printf("\n");
}