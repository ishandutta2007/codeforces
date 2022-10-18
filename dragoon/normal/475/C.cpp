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

char board[1003][1003];
int placed[1003][1003];
int sum[1003][1003];
int R, C;

int canPlace(int r, int c, int x, int y)
{
	if(r + y - 1 > R || c + x - 1 > C) return 0;
	int now = sum[r + y - 1][c + x - 1] - sum[r + y - 1][c - 1] - sum[r - 1][c + x - 1] + sum[r - 1][c - 1];
	return (now == x * y);
}

int check(int x, int y, int lr, int lc)
{
	CLR(placed);

	int i, j;
	int nowr = lr, nowc = lc;
	if(!canPlace(nowr,nowc,x,y)) return -1;
	for(i = lr; i <= lr + y - 1; i++)
		for(j = lc; j <= lc + x - 1; j++)
			placed[i][j] = 1;

	while(true)
	{
		if(canPlace(nowr + 1, nowc,x,y))
		{
			for(i = 1; i <= x; i++)
				placed[nowr + y][nowc + i - 1] = 1;
			nowr++;
			continue;
		}
		if(canPlace(nowr, nowc + 1,x,y))
		{
			for(i = 1; i <= y; i++)
				placed[nowr + i - 1][nowc + x] = 1;
			nowc++;
			continue;
		}
		break;
	}
	for(i = 0; i <= R + 1; i++)
		for(j = 0; j <= C + 1; j++)
		{
			if( (board[i][j] == 'X' && placed[i][j] == 1) || (board[i][j] == '.' && placed[i][j] == 0) ) continue;
			else return -1;
		}

	return x * y;
}

int find()
{
	int i, j;
	int x, y;

	for(i = 0; i <= R + 1; i++) board[i][0] = board[i][C + 1] = '.';
	for(i = 0; i <= C + 1; i++) board[0][i] = board[R + 1][i] = '.';

	int lr = 1003, hr = -1003;
	int lc = 1003, hc = -1003;
	int cross = 0;

	FORAB(i, 1, R) FORAB(j, 1, C)  if(board[i][j] == 'X')
	{
		cross++;
		lr = MIN(lr, i);
		hr = MAX(hr, i);
		lc = MIN(lc, j);
		hc = MAX(hc, j);
	}

	if(cross == 0) return 0;

	if(cross == (hr - lr + 1) * (hc - lc + 1))
	{
		return MIN(hr - lr + 1, hc - lc + 1);
	}

	FORAB(i, 0, R + 1) FORAB(j, 0, C + 1) sum[i][j] = (board[i][j] == 'X');
	FORAB(i, 0, R + 1) FORAB(j, 0, C + 1)
	{
		if(i) sum[i][j] += sum[i - 1][j];
		if(j) sum[i][j] += sum[i][j - 1];
		if(i && j) sum[i][j] -= sum[i - 1][j - 1];
	}

	if(board[lr][lc] == '.') return -1;

	int ans1 = -1, ans2 = -1;
	int ans, flag = 1;
	while(flag)
	{
		for(j = lc; j <= C + 1; j++) if(board[lr][j] == '.') break; if(j == C + 2) {flag = 0; continue;}
		for(i = lr; i <= R + 1; i++) if(board[i][j] == 'X') break; if(i == R + 2) {flag = 0; continue;}
		i--;
		int si = i, sj = j;
		for(i = lr; i <= R + 1; i++) if(board[i][lc] == '.') break; if(i == R + 2) {flag = 0; continue;}
		int ni = i, nj = lc;
		y = ni - si - 1;
		x = sj - nj;
		if(x < 1 || y < 1) break;
		ans = check(x, y, lr, lc);
		if(ans != -1) {ans1 = ans; break;};
		break;
	}

	flag = 1;
	while(flag)
	{
		for(i = lr; i <= R + 1; i++) if(board[i][lc] == '.') break; if(i == R + 2) {flag = 0; continue;}
		for(j = lc; j <= C + 1; j++) if(board[i][j] == 'X') break; if(j == C + 2) {flag = 0; continue;}
		j--;
		int si = i, sj = j;
		for(j = lc; j <= C + 1; j++) if(board[lr][j] == '.') break; if(j == C + 2) {flag = 0; continue;}
		int ni = lr, nj = j;
		y = si - ni;
		x = nj - sj - 1;
		if(x < 1 || y < 1) break;
		ans = check(x, y, lr, lc);
		if(ans != -1) {ans2 = ans; break;};
		break;
	}

	if(ans1 == -1) return ans2;
	if(ans2 == -1) return ans1;

	return MIN(ans1, ans2);

	return -1;
}

int main()
{
	int i, j;

	scanf("%d %d", &R, &C);
	for(i = 1; i <= R; i++) scanf("%s", board[i] + 1);

	int ans = find();
	printf("%d\n", ans);

	return 0;
}