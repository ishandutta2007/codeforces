#pragma warning(disable:4786)
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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


char grid[3][10004];
int dp[3][10004][1<<3];
int MOD = 1000000007;
int n;

inline int inside(int i, int j)
{
	if(i < 0 || j < 0 || i >= 3 || j >= n) return 0;
	return 1;
}

int DP(int r, int c, int mask)
{
	if(r == 3) return DP(0, c + 1, mask);
	if(c == n)
	{
		return mask == 0;
	}

	int &ret = dp[r][c][mask];
	if(ret != -1) return ret;
	ret = 0;

	if(grid[r][c]!='.' && (mask&(1<<r))) return ret = 0;
	if(grid[r][c]!='.') return ret = DP(r + 1, c, mask);

	if(mask&(1<<r)) return ret = DP(r + 1, c, mask^(1<<r));

	if(r < 2 && !(mask&(1<<(r+1))))
	{
		ret = DP(r + 1, c, mask | (1<<(r+1)));
	}

	ret = (ret + DP(r + 1, c, mask | (1<<r)))%MOD;

	return ret;
}

int si, sj;

int calc(int mask)
{
	int d, flag = 0, ret = 0;

	for(d = 0; d < 4; d++) if(mask & (1<<d))
	{
		if(!inside(si - dr[d]*2, sj - dc[d]*2)) {flag = 1; goto end;}
		if(grid[si - dr[d]][sj - dc[d]] != '.') {flag = 1; goto end;}
		if(grid[si - 2*dr[d]][sj - 2*dc[d]] != '.') {flag = 1; goto end;}

		if(grid[si - dr[d]][sj - dc[d]] == '.') grid[si - dr[d]][sj - dc[d]] = 'A';
		if(grid[si - 2*dr[d]][sj - 2*dc[d]] == '.') grid[si - 2*dr[d]][sj - 2*dc[d]] = 'A';
	}

	MEM(dp, -1);

	ret = DP(0, 0, 0);

end:
	for(d = 0; d < 4; d++) if(mask & (1<<d))
	{
		if(grid[si - dr[d]][sj - dc[d]] == 'A') grid[si - dr[d]][sj - dc[d]] = '.';
		if(grid[si - 2*dr[d]][sj - 2*dc[d]] == 'A') grid[si - 2*dr[d]][sj - 2*dc[d]] = '.';
	}

//	printf("%d %d\n", mask, ret);
	return ret;
}

int main()
{
	int i, j, cnt;
	int ans = 0;

	scanf("%d", &n);
	scanf("%s%s%s", grid[0], grid[1], grid[2]);

	for(i = 0; i < 3; i++)
		for(j = 0; j < n; j++)
			if(grid[i][j] == 'O')
				si = i, sj = j;

	for(i = 1; i < (1<<4); i++)
	{
		cnt = (i&1) + ((i>>1)&1) + ((i>>2)&1) + ((i>>3)&1);

		if(cnt&1)
			ans = (ans + calc(i))%MOD;
		else
			ans = (ans + (MOD - calc(i)))%MOD;
	}

	printf("%d\n", ans);

	return 0;
}