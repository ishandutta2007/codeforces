#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
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
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int n;
char word[5005];
int nexts[5005][26];
LL MOD = 1000000007;
int dp[2][5005];

int DP(int at, int prev) {
	if (at == n + 1) return 1;
	if (prev == n + 1) return 0;
	int &ret = dp[at][prev];
	if (ret != -1) return ret;

	LL ans = 0;
	for (int i = 0; i < 26; i++) {
		if (nexts[prev][i] == n + 1) continue;
		ans += DP(at + 1, nexts[prev][i]);
		ans %= MOD;
	}
	return ret = ans;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", word + 1);

	for (int i = 0; i < 26; i++) nexts[n + 1][i] = n + 1;
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j < 26; j++) nexts[i][j] = nexts[i + 1][j];
		if (i) nexts[i][word[i] - 'a'] = i;
	}

	int u = 0, v = 1;
	for (int i = 1; i <= n; i++) dp[u][i] = 1;

	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 0; j--) {
			LL ans = 0;
			for (int k = 0; k < 26; k++) {
				if (nexts[j][k] == n + 1) continue;
				ans += dp[u][nexts[j][k]];
			}
			dp[v][j] = ans % MOD;
		}
		u ^= 1;
		v ^= 1;
	}

	int ans = dp[u][0];
	printf("%d\n", ans);

	return 0;
}