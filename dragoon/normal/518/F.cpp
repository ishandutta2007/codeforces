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
typedef __int64 LL;

char board[2005][2005];
int lefts[2005][2005];
int up[2005][2005];
int down[2005][2005];
int rights[2005][2005];

int main()
{
	int n, m;
	int i, j;

	scanf("%d %d", &n, &m);
	{
		for(i = 0; i < n; i++)
			scanf("%s", board[i]);

		LL ans = 0;

		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
			{
				if(i == 0) up[i][j] = -1;
				else up[i][j] = up[i - 1][j];
				if(board[i][j] == '#') up[i][j] = i;
			}

		for(i = n - 1; i >= 0; i--)
			for(j = 0; j < m; j++)
			{
				if(i == n - 1) down[i][j] = n;
				else down[i][j] = down[i + 1][j];
				if(board[i][j] == '#') down[i][j] = i;
			}

		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
			{
				if(j == 0) lefts[i][j] = -1;
				else lefts[i][j] = lefts[i][j - 1];
				if(board[i][j] == '#') lefts[i][j] = j;
			}

		for(i = 0; i < n; i++)
			for(j = m - 1; j >= 0; j--)
			{
				if(j == m - 1) rights[i][j] = m;
				else rights[i][j] = rights[i][j + 1];
				if(board[i][j] == '#') rights[i][j] = j;
			}

		for(i = 1; i < n - 1; i++)
		{
			if(lefts[i][1] == -1 && rights[i][1] == m)
				ans++;
		}

		for(j = 1; j < m - 1; j++)
		{
			if(up[1][j] == -1 && down[1][j] == n)
				ans++;
		}

		for(i = 1; i < n - 1; i++)
			for(j = 1; j < m - 1; j++)
			{
				if(lefts[i][j] == -1 && up[i][j] == -1) ans++;
				if(lefts[i][j] == -1 && down[i][j] == n) ans++;
				if(rights[i][j] == m && up[i][j] == -1) ans++;
				if(rights[i][j] == m && down[i][j] == n) ans++;
			}

		for(j = 1; j < m - 1; j++)
		{
			int L, R;
			int pL, pR;
			L = R = 0;
			pL = pR = 0;
			for(i = 1; i < n - 1; i++)
			{
				if(lefts[i][j] == -1) ans += R, ans += pL;
				if(rights[i][j] == m) ans += L, ans += pR;
				pL = L, pR = R;
				if(lefts[i][j] == -1) L++;
				if(rights[i][j] == m) R++;
				if(board[i][j] == '#') pL = pR = L = R = 0;
			}
		}

		for(i = 1; i < n - 1; i++)
		{
			int U, D;
			int pU, pD;
			U = D = 0;
			pU = pD = 0;
			for(j = 1; j < m - 1; j++)
			{
				if(up[i][j] == -1) ans += D, ans += pU;
				if(down[i][j] == n) ans += U, ans += pD;
				pD = D, pU = U;
				if(down[i][j] == n) D++;
				if(up[i][j] == -1) U++;
				if(board[i][j] == '#') pU = pD = U = D = 0;
			}
		}

		printf("%I64d\n", ans);
	}

	return 0;
}