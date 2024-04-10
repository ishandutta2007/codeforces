//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<PLL > VPL;
typedef vector<double> VD;
typedef long double ld;

char S[100005];
int nxt[100005][26];
int lenS, q;

char Q[4][500];
int lenQ[3];
int dp[252][252][252];

void Calc(int i, int j, int k) {
	dp[i][j][k] = lenS;
	if (i) {
		int x = dp[i - 1][j][k];
		if (x != lenS) {
			int temp = nxt[x + 1][Q[0][i] - 'a'];
			dp[i][j][k] = MIN(dp[i][j][k], temp);
		}
	}
	if (j) {
		int x = dp[i][j - 1][k];
		if (x != lenS) {
			int temp = nxt[x + 1][Q[1][j] - 'a'];
			dp[i][j][k] = MIN(dp[i][j][k], temp);
		}
	}
	if (k) {
		int x = dp[i][j][k - 1];
		if (x != lenS) {
			int temp = nxt[x + 1][Q[2][k] - 'a'];
			dp[i][j][k] = MIN(dp[i][j][k], temp);
		}
	}
}

void solve(int ks) {
	scanf("%d %d %s", &lenS, &q, S);
	for (int i = 0; i < 26; i++) {
		nxt[lenS][i] = lenS;
		for (int j = lenS - 1; j >= 0; j--) {
			nxt[j][i] = nxt[j + 1][i];
			if (S[j] == i + 'a') nxt[j][i] = j;
		}
	}

	for (int i = 0; i < 252; i++) {
		for (int j = 0; j < 252; j++) {
			for (int k = 0; k < 252; k++) {
				dp[i][j][k] = lenS;
			}
		}
	}

	dp[0][0][0] = -1;
	for (int qq = 1; qq <= q; qq++) {
		char op[3]; int at; char ch[3];
		scanf("%s %d", op, &at);
		at--;
		if (op[0] == '+') {
			scanf("%s", ch);
			Q[at][++lenQ[at]] = ch[0];
			if (at == 0) {
				int i = lenQ[0];
				for (int j = 0; j <= lenQ[1]; j++) {
					for (int k = 0; k <= lenQ[2]; k++) {
						Calc(i, j, k);
					}
				}
			}
			else if (at == 1) {
				int i = lenQ[1];
				for (int j = 0; j <= lenQ[0]; j++) {
					for (int k = 0; k <= lenQ[2]; k++) {
						Calc(j, i, k);
					}
				}
			}
			else if (at == 2) {
				int i = lenQ[2];
				for (int j = 0; j <= lenQ[0]; j++) {
					for (int k = 0; k <= lenQ[1]; k++) {
						Calc(j, k, i);
					}
				}
			}
		}
		else {
			lenQ[at]--;
		}

		printf("%s\n", dp[lenQ[0]][lenQ[1]][lenQ[2]] < lenS ? "YES" : "NO");
	}
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif


	if (0) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 25);
		for (int ks = 1; ks <= T; ks++) solve(ks);
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}