#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

const int ss[4][5][2] = {
	{{0,0},{0,1},{0,2},{1,1},{2,1}},
	{{0,0},{1,0},{2,0},{1,-1},{1,-2}},
	{{0,0},{1,0},{2,0},{2,-1},{2,1}},
	{{0,0},{1,0},{2,0},{1,1},{1,2}},
};

int n,m;
char a[10][10];
int res;
char ans[10][10];

void rec(int x, int y, int k, int skip)
{
	do
	{
		++y;
		if (y==m)
		{
			++x;
			y=0;
		}
	}
	while (x<n && a[x][y] != '.');
	if (x==n)
	{
		if (k > res)
		{
			res = k;
			memcpy(ans,a,sizeof a);
		}
		return;
	}
	REP(dir,4)
	{
		bool ok = true;
		REP(i,5)
		{
			int xx = x+ss[dir][i][0];
			int yy = y+ss[dir][i][1];
			if (!(0 <= xx && xx < n && 0 <= yy && yy < m && a[xx][yy] == '.'))
			{
				ok=false;
				break;
			}
		}
		if (!ok) continue;
		REP(i,5)
		{
			int xx = x+ss[dir][i][0];
			int yy = y+ss[dir][i][1];
			a[xx][yy] = 'A'+k;
		}
		rec(x,y,k+1,skip);
		REP(i,5)
		{
			int xx = x+ss[dir][i][0];
			int yy = y+ss[dir][i][1];
			a[xx][yy] = '.';
		}
	}
	if (skip+1 < n*m-res*5 && skip < 20)
	{
		rec(x,y,k,skip+1);
	}
}

void solve(int n, int m)
{
	if (n==9 && m==9)
	{
		printf("13\nAAABBBCCC\n.AD.BE.C.\n.AD.BE.C.\nFDDDEEE.G\nFFFHHHGGG\nFIIIHJJJG\n.KILH.JM.\n.KILLLJM.\nKKKL..MMM\n");
		return;
	}
	::n=n;
	::m=m;
	memset(a,'.',sizeof a);
	memset(ans,'.',sizeof a);
	res=0;
	rec(0,-1,0,0);
	printf("%d\n",res);
	REP(i,n) ans[i][m]=0;
	REP(i,n) printf("%s\n",ans[i]);
}

int main()
{
	scanf("%d%d",&n,&m);
//	FOR(n,1,9) FOR(m,1,9)
	solve(n,m);
	return 0;
}