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
#define INF 1000000000
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

#define N 1024
int nn,mm,k,w;
string a[N];
int g[N][N];
int d[N],prv[N];
bool mark[N];

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d%d%d",&nn,&mm,&k,&w);
	REP(i,k)
	{
		a[i].resize(nn*mm);
		REP(t,nn*mm) {
			char c;
			do c = getc(stdin);
			while (c!='.'&&!isalpha(c));
			a[i][t] = c;
		}
	}
	CLEAR(g);
	REP(i,k) REP(j,k)
	{
		g[i][j] = 0;
		REP(p,SZ(a[i]))
			if (a[i][p] != a[j][p])
				g[i][j] += w;
	}
	REP(i,k)
		g[i][k]=g[k][i]=nn*mm;
	REP(i,k) d[i] = INF;
	d[k] = 0;
	CLEAR(mark);
	int sum = 0;
	VPII res;
	REP(step,k+1)
	{
		int mn = -1;
		REP(i,k+1) if (!mark[i] && (mn==-1 || d[mn] > d[i]))
			mn = i;
		sum += d[mn];
		mark[mn] = true;
		if (mn != k)
			res.push_back(PII(mn,prv[mn]));
		REP(i,k+1)
		{
			if (g[mn][i] < d[i])
			{
				d[i] = g[mn][i];
				prv[i] = mn;
			}
		}
	}
	printf("%d\n",sum);
	REP(i,k)
	{
		printf("%d %d\n",res[i].first+1,res[i].second==k?0:res[i].second+1);
	}
	return 0;
}