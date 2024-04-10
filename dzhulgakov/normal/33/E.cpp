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

#define LEN 50000
#define N 128
int m,n,k;
char buf[100];
string names[N];
map<string,int> dur;
VPII gaps;
int cost[N];
int len[N];
int deadline[N];
PII order[N];
bool oneday[24*60+1000];
int d[N][LEN];
int prev[N][LEN];
int daylen;

int from(int day, int time)
{
	int res = 0;
	REP(i,day-1)
	{
		res += daylen;
	}
	REP(i,time)
	{
		if (!oneday[i])
			res++;
	}
	return res;
}

int readtime()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	return h*60+m;
}

void printtime(int x)
{
	int day = 1;
	while (x > daylen)
	{
		x-=daylen;
		day++;
	}
	int tmm=0;
	while (x)
	{
		if (!oneday[tmm])
		{
			x--;
			if (x == 0) break;
		}
		tmm++;
	}
	printf(" %d %02d:%02d",day,tmm/60,tmm%60);
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d%d",&m,&n,&k);
	REP(i,m)
	{
		scanf("%s",buf);
		names[i]=string(buf);
	}
	REP(i,m)
	{
		int x;
		scanf("%d",&x);
		dur[names[i]]=x;
	}
	CLEAR(oneday);
	REP(i,4)
	{
		int st = readtime();
		scanf("-");
		int fn = readtime();
		gaps.push_back(PII(st,fn));
		FOR(x,st,fn) 
			oneday[x] = true;
	}
	daylen = 24*60;
		REP(j,4)
			daylen -= gaps[j].Y-gaps[j].X+1;
	REP(i,n)
	{
		int day;
		scanf("%s %d",buf,&day);
		int time = readtime();
		deadline[i] = from(day, time);
		if (dur.count(string(buf)) > 0)
			len[i] = dur[string(buf)];
		else
			len[i] = LEN*5;
		scanf("%d",&cost[i]);
		order[i]=PII(deadline[i],i);
	}
	sort(order,order+n);
	CLEAR(d);
	FILL(prev,-1);
	REP(ii,n)
	{
		int i = order[ii].second;
		REP(x,LEN)
		{
			d[ii+1][x] = d[ii][x];
			prev[ii+1][x] = -1;
		}
		FOR(x,0,deadline[i]-len[i])
		{
			int q = d[ii][x]+cost[i];
			if (q > d[ii+1][x+len[i]])
			{
				d[ii+1][x+len[i]] = q;
				prev[ii+1][x+len[i]] = i;
			}
		}
	}
	int mxp = 0;
	REP(x,LEN) if (d[n][mxp] < d[n][x])
		mxp=x;
	printf("%d\n",d[n][mxp]);
	VPII ans;
	REPD(ii,n)
	{
		int i = order[ii].second;
		if (prev[ii+1][mxp] == -1)
			continue;
		ans.push_back(PII(i,mxp-len[i]+1));
		mxp-=len[i];
	}
	reverse(ALL(ans));
	printf("%d\n",SZ(ans));
	REP(i,SZ(ans))
	{
		int id = ans[i].first;
		printf("%d",id+1);
		printtime(ans[i].second);
		printtime(ans[i].second+len[id]-1);
		printf("\n");
	}
	return 0;
}