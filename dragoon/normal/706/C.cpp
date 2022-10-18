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

int cost[100005];
LL dp[100005][2];
char word[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);

	LL LIM = 1000000000;
	LIM *= LIM;

	string S = "", SR = "";
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", word);
		string T = word;
		string TR = T;
		reverse(TR.begin(), TR.end());

		// put T.
		dp[i][0] = dp[i][1] = LIM;
		if (S <= T) dp[i][0] = MIN(dp[i][0], dp[i - 1][0]);
		if (SR <= T) dp[i][0] = MIN(dp[i][0], dp[i - 1][1]);

		// put TR
		if (S <= TR) dp[i][1] = MIN(dp[i][1], dp[i - 1][0] + cost[i]);
		if (SR <= TR) dp[i][1] = MIN(dp[i][1], dp[i - 1][1] + cost[i]);

		S = T, SR = TR;
	}

	LL ans = MIN(dp[n][0], dp[n][1]);
	if (ans == LIM) printf("-1\n");
	else printf("%I64d\n", ans);
	return 0;
}