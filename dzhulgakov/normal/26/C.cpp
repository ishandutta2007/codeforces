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

#define N 128
int n,m,nn,mm;
int s,v,h;
int a[N][N];
int k = 0;

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d%d%d%d",&n,&m,&h,&v,&s);
	nn=n,mm=m;
	if ((n*m) % 2 != 0)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	if (n % 2 == 1)
	{
		for (int i = 0; i < m; i+=2)
			a[n-1][i]=a[n-1][i+1]=k++,h--;
	}
	if (m % 2 == 1)
	{
		for (int i = 0; i < n; i+=2)
			a[i][m-1]=a[i+1][m-1]=k++,v--;
	}
	for (int i = 0; i+1 < n; i+=2) for (int j = 0; j+1 < m; j+=2)
		if (v>=2)
		{
			a[i][j]=a[i+1][j]=k++; v--;
			a[i][j+1]=a[i+1][j+1]=k++; v--;
		}
		else if (h>=2)
		{
			a[i][j]=a[i][j+1]=k++; h--;
			a[i+1][j]=a[i+1][j+1]=k++; h--;
		}
		else
		{
			a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]=k++; s--;
		}
	if (v<0||h<0||s<0)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	REP(i,n)
	{
		REP(j,m)
		{
			int x=i,y=j;
			while (x>0 && a[x-1][y] == a[x][y]) x--;
			while (y>0 && a[x][y-1] == a[x][y]) y--;
			printf("%c",'a'+((x%5)*5+y%5));
		}
		printf("\n");
	}
	return 0;
}