#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 705
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int dp[2][N][N], ok[N][N];
int a[N];
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

// op = 0 is dp_l
int DP(int L, int R, int op)
{
	//debug(L);
	//debug(R);
	if (R < L)
		return 1;
	if (dp[op][L][R] != -1)
		return dp[op][L][R];
	int fa = op == 0 ? R + 1 : L - 1;
	if (L == R)
	{
		if (ok[L][fa])
		{
			return dp[op][L][R] = 1;
		}
		else
			return dp[op][L][R] = 0;
	}
	int i;
	for (i = L; i <= R; i++)
	{
		if (ok[i][fa])
			if (DP(L, i - 1, 0) && DP(i + 1, R, 1))
			{
				return dp[op][L][R] = 1;
			}
	}
	return dp[op][L][R] = 0;
}

int main()
{
	int n, i, j;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	a[n + 1] = a[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i <= n+1; i++)
		for (j = 0; j <= n+1; j++)
			if (gcd(a[i], a[j]) > 1)
				ok[i][j] = 1;
	DP(1, n, 0);
	if (dp[0][1][n] == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/