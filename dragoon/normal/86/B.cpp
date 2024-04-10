#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef pair<int,int> PII;
typedef __int64 LL;

vector<PII> V[1002][1002];
int dirr[]={0,-1,1,0};
int dirc[]={1,0,0,-1};
char grid[1002][1002];
int R,C;
int done[400];

void dfs(int r, int c)
{
	int k, nr, nc;

	grid[r][c]='X';
	int i, sz = V[r][c].size();
	for(k=0;k<4;k++)
	{
		nr = r+dirr[k];
		nc = c+dirc[k];

		if(nr<0 || nr>=R || nc<0 || nc>=C) continue;
		if(grid[nr][nc]>='0' && grid[nr][nc]<='9') 
			done[ grid[nr][nc] ] = 1;
	}

	for(i=0;i<sz;i++)
		if( grid[ V[r][c][i].first ][ V[r][c][i].second ] == 'x' )
		{
			dfs( V[r][c][i].first, V[r][c][i].second );
		}
}

void color(int r, int c, char cc)
{
	grid[r][c]=cc;
	int i, sz = V[r][c].size();
	for(i=0;i<sz;i++)
		if( grid[ V[r][c][i].first ][ V[r][c][i].second ] == 'X' )
		{
			color( V[r][c][i].first, V[r][c][i].second, cc );
		}
}

int main()
{
	scanf("%d%d",&R,&C);

	int i, ok, j, k, ni, nj;

	for(i=0;i<R;i++)
		scanf("%s",grid[i]);

	ok = 1;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			if(grid[i][j]=='.')
			{
				grid[i][j]='x';

				for(k=0;k<4;k++)
				{
					ni = i + dirr[k];
					nj = j + dirc[k];

					if(ni<0 || ni>=R || nj<0 || nj>=C) continue;
					if(grid[ni][nj]=='.')
					{
						grid[ni][nj]='x';
						V[i][j].push_back( PII(ni,nj) );
						V[i][nj].push_back( PII(i,j) );
						goto ee;
					}
				}

				for(k=0;k<4;k++)
				{
					ni = i + dirr[k];
					nj = j + dirc[k];

					if(ni<0 || ni>=R || nj<0 || nj>=C) continue;
					if(grid[ni][nj]=='x')
					{
						grid[ni][nj]='x';
						V[i][j].push_back( PII(ni,nj) );
						V[ni][nj].push_back( PII(i,j) );
						goto ee;
					}
				}
					ok = 0;
					goto e;


ee:
					ok = ok;
			}

e:
		if(ok==0)
		{
			printf("-1\n");
			return 0;
		}

	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			if(grid[i][j]=='x')
			{
				for(k='0';k<='9';k++) done[k]=0;
				dfs(i,j);
				for(k='0';k<='9';k++)
					if( !done[k] )
						break;

				color( i, j, k );
			}

	for(i=0;i<R;i++) printf("%s\n",grid[i]);


	return 0;
}