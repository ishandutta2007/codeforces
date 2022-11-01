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

int n,m;
char a[32][32];
int b[32][32];
int ans[32][32];
bool isans=false;
int res = 0;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void rec(int maxc, int x, int y, LL mask)
{
	while (a[x][y] == '.' || b[x][y] != -1)
	{
		y++;
		if (y==m)
		{
			x++;
			y=0;
		}
		if (x==n)
		{
			++res;
			if (!isans)
			{
				memcpy(ans,b,sizeof ans);
				isans=true;
			}
			return;
		}
	}
	FOR(clr,0,min(maxc+1,6))
	{
		bool bad = false;
		REP(i,2) REP(j,2)
		{
			if (i+x >= n || j+y >= m || a[i+x][j+y] == '.' || b[i+x][j+y] != -1)
			{
				bad = true;
				break;
			}
		}
		if (bad) continue;
		REP(i,2) REP(j,2)
			b[i+x][j+y] = clr;
		LL nmask = mask;
		REP(i,2) REP(j,2)
		{
			int xx = x+i;
			int yy = y+j;
			REP(dir,4)
			{
				int xxx = xx + dx[dir];
				int yyy = yy + dy[dir];
				if (0<=xxx&&xxx<n && 0<=yyy&&yyy<m && a[xx][yy] == a[xxx][yyy] && b[xxx][yyy] != -1)
				{
					if (x <= xxx && xxx <= x+1 && y <= yyy && yyy <= y+1)
						if (PII(xx,yy) > PII(xxx,yyy))
							continue;
					int c1 = b[xx][yy]*7 + b[xxx][yyy];
					int c2 = b[xx][yy] + 7*b[xxx][yyy];
					if (nmask&(1LL<<c1))
					{
						goto exit;
					}
					nmask |= 1LL<<c1;
					nmask |= 1LL<<c2;
				}
			}
		}
		rec(max(maxc,clr),x,y,nmask);
		exit:
		REP(i,2) REP(j,2)
			b[i+x][j+y] = -1;
	}
}

int main()
{
	//freopen("a.in","r",stdin);

	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%s",a+i);
	FILL(b,-1);
	rec(-1,0,0,0);
	FOR(i,1,7) res *= i;
	printf("%d\n",res);
	REP(i,n)
	{
		REP(j,m)
			if (a[i][j]=='.')
				printf(".");
			else
				printf("%d",ans[i][j]);
		printf("\n");
	}
	return 0;
}