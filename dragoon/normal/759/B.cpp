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
//typedef long long int LL;
//typedef __int64 LL;

int n;
int t[100005];
int dp[100005];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}

	t[0] = -1000000;
	dp[0] = 0;
	int i2 = 0, i3 = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 20 + dp[i - 1];
		while (t[i2 + 1] < t[i] - 90 + 1) i2++;
		dp[i] = MIN(dp[i], 50 + dp[i2]);
		while (t[i3 + 1] < t[i] - 1440 + 1) i3++;
		dp[i] = MIN(dp[i], 120 + dp[i3]);
	}

	for (int i = 1; i <= n; i++)  {
		printf("%d\n", dp[i] - dp[i - 1]);
	}

	return 0;
}