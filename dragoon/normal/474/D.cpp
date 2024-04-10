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

LL MOD = 1000000007;
LL dp[100005];

int main()
{
	int t, k, a, b;

	scanf("%d %d", &t, &k);

	dp[0] = 1;
	for(int i = 1; i <= 100001; i++)
	{
		dp[i] = dp[i - 1];
		if(i - k >= 0) dp[i] += dp[i - k];
		dp[i] %= MOD;
	}

	for(int i = 1; i <= 100001; i++)
		dp[i] = (dp[i] + dp[i - 1]) % MOD;

	for(int i = 1; i <= t; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%I64d\n", (dp[b] - dp[a - 1] + MOD) % MOD);
	}

	return 0;
}