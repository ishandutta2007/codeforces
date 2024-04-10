#pragma warning(disable:4786)
#include<list>
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

char grid[600][600];
queue<PII> Q;
int vis[600][600];
vector<PII > V;
int R, C, r, c, k;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main()
{
	int i, j, d, sr, sc, sz;
	PII u;

	scanf("%d %d %d", &R, &C, &k);
	FORN(i, R) scanf("%s", grid[i]);

	FORN(i, R) FORN(j, C)
		if(grid[i][j] == '.')
			sr = i, sc = j;

V.push_back(PII(sr,sc));
	Q.push( PII(sr, sc) );
	vis[sr][sc] = 1;

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		for(d = 0; d < 4; d++)
		{
			r = u.first + dr[d];
			c = u.second + dc[d];

			if(r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == '#' || vis[r][c] == 1) continue;

		vis[r][c] = 1;
			Q.push(PII(r,c));
			V.push_back(PII(r,c));
		}
	}

	sz = SZ(V);
	for(i = 0; i < k; i++)
		grid[ V[sz - i - 1].first ][V[sz - i - 1].second] = 'X';

	FORN(i, R) printf("%s\n", grid[i]);

	return 0;
}