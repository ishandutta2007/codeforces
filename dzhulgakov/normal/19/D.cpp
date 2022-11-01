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

#define N 266000
int n,m;
pair<int,PII> cmd[N];
PII pnts[N];
int xx[N],xxk;
int pw2;
int mx[N*2];
set<int> a[N];

void put(int x, int val)
{
	x+=pw2;
	mx[x] = val;
	for (x/=2; x>=1; x/=2)
		mx[x] = max(mx[2*x],mx[2*x+1]);
}

PII solve(int ix, int y)
{
	PII res(-1,-1);
	if (ix+1 == xxk) return res;
	int w = pw2+ix+1;
	while (w > 1 && mx[w] <= y)
	{
		while (w > 1 && w%2 == 1)
			w/=2;
		if (w>1) w^=1;
	}
	if (w==1 || mx[w] <= y) return res;
	while (w < pw2)
		if (mx[2*w] > y)
			w = 2*w;
		else
			w = 2*w+1;
	set<int>::iterator it = a[w-pw2].lower_bound(y+1);
	return PII(xx[w-pw2],*it);
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	m=n;
	REP(i,m)
	{
		char buf[100];
		scanf("%s %d %d",buf,&cmd[i].second.X,&cmd[i].second.Y);
		cmd[i].first = !strcmp(buf,"add") ? +1 : !strcmp(buf,"remove") ? -1 : 0;
		pnts[i] = cmd[i].second;
	}
	sort(pnts,pnts+n);
	n=unique(pnts,pnts+n)-pnts;
	xxk=0;
	REP(i,n)
		if (xxk==0 || xx[xxk-1] != pnts[i].X)
			xx[xxk++] = pnts[i].X;
	for (pw2=1; pw2<xxk; pw2<<=1) ;
	REP(i,pw2*2)
		mx[i] = -INF;
	REP(i,m)
	{
		PII p = cmd[i].second;
		int ix = lower_bound(xx,xx+xxk,p.X)-xx;
		if (cmd[i].first > 0)
		{
			a[ix].insert(p.Y);
			if (p.Y > mx[ix+pw2])
				put(ix, p.Y);
		}
		else if (cmd[i].first < 0)
		{
			a[ix].erase(p.Y);
			if (a[ix].empty())
				put(ix,-INF);
			else
			{
				set<int>::iterator it = a[ix].end();
				it--;
				put(ix,*it);
			}
		}
		else
		{
			PII res = solve(ix,p.Y);
			if (res.X == -1)
				printf("-1\n");
			else
				printf("%d %d\n",res.X,res.Y);
		}
	}
	return 0;
}