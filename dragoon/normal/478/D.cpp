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
int dp[2][200005];

int main()
{
	int r, g;
	cin >> r >> g;
	if(r > g) swap(r, g);

	if(!r && !g) 
	{
		printf("0\n");
		return 0;
	}

	int h;
	LL sum = 0;
	for(h = 1; ; h++)
	{
		if(sum + h > r + g) break;
		sum += h;
	}

	h--;

	int H = h;
	int R, G;

	int u = 0, v = 1;

	dp[u][r] = 1;
	sum = 0;
	for(h = 1; h <= H; h++)
	{
		for(R = 0; R <= r; R++) dp[v][R] = 0;
		for(R = 0; R <= r; R++) if(r - R <= sum)
		{
			G = g - (sum - (r - R));
			if(R >= h) dp[v][R - h] = (dp[v][R - h] + dp[u][R]) % MOD;
			if(G >= h) dp[v][R] = (dp[v][R] + dp[u][R]) % MOD;
		}
		sum += h;
		u ^= 1, v ^= 1;
	}
	
	sum = 0;
	for(int i = 0; i <= r; i++) sum = (sum + dp[u][i]) % MOD;

	printf("%I64d\n", sum);
	
	return 0;
}