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

void check(PII &ret, PII now, int side) {
	if (side == 0) {
		if (now.first > ret.first ||
			(now.first == ret.first && now.second < ret.second)) {
			ret = now;
		}
	}
	else {
		if (now.second > ret.second ||
			(now.second == ret.second && now.first < ret.first)) {
			ret = now;
		}
	}
}

int n;
int arr[100];
PII dp[102][2];
int vis[102][2];
PII DP(int a, int side) {
	if (a > n) {
		return PII(0, 0);
	}

	if (vis[a][side]) {
		return dp[a][side];
	}

	vis[a][side] = 1;
	PII now;
	PII &ret = dp[a][side];
	int val;
	ret = PII(-1000000, -1000000);

	// take a, take by self.
	now = DP(a + 1, side ^ 1);
	val = arr[a];
	if (side == 0) now.first += val; else now.second += val;
	check(ret, now, side);

	// take a, give to opp.
	now = DP(a + 1, side);
	val = arr[a];
	if (side == 1) now.first += val; else now.second += val;
	check(ret, now, side);

	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	PII ans = DP(1, 0);
	printf("%d %d\n", ans.second, ans.first);

	return 0;
}