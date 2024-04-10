#include <algorithm>
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

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

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

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;

typedef long long LL;

#define N 155000
int n;
char a[N];
PII order[N];
int cost[N][2];
int pw2;
int sum[2*N],mn[2*N];

void up(int v)
{
	sum[v] = 0;
	mn[v] = 0;
	if (2*v < pw2+n)
	{
		mn[v] = min(mn[v], sum[v]+mn[2*v]);
		sum[v] += sum[2*v];
	}
	if (2*v+1 < pw2+n)
	{
		mn[v] = min(mn[v], sum[v]+mn[2*v+1]);
		sum[v] += sum[2*v+1];
	}
}

void modify(int v, int by)
{
	sum[v] += by;
	mn[v] = min(0,sum[v]);
	for (v/=2; v; v/=2)
		up(v);
}

set<int> moveable[2];
char res[N];

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("data.in","r",stdin);
#endif
	gets(a);
	n=strlen(a);
	for (pw2=1; pw2<n; pw2<<=1) ;
	REP(i,n)
	{
		if (a[i]=='?')
			scanf("%d%d",&cost[i][0],&cost[i][1]);
		else
		{
			cost[i][0]=cost[i][1]=0;
			cost[i][a[i]=='(']=INF;
		}
		order[i] = PII(abs(cost[i][0]-cost[i][1]), i);
	}
	REP(i,n)
	{
		sum[pw2+i] = i<n/2 ? +1 : -1;
		mn[pw2+i] = min(0,sum[pw2+i]);
		moveable[i/(n/2)].insert(i);
		res[i] = '('+(i/(n/2));
	}
	for (int i = pw2-1; i>=1; i--)
		up(i);
	sort(order,order+n,greater<PII>());
	LL ans = 0;
	REP(ii,n)
	{
		int i = order[ii].second;
		char want = cost[i][0] < cost[i][1] ? '(' : ')';
		if (want != res[i])
		{
			int replace;
			if (res[i]=='(')
			{
				set<int>::iterator it = moveable[1].begin();
				if (it==moveable[1].end())
					replace=-1;
				else
					replace = *it;
			}
			else
			{
				set<int>::iterator it = moveable[0].end();
				if (it==moveable[0].begin())
					replace=-1;
				else
				{
					it--;
					replace = *it;
				}
			}
			if (replace != -1)
			{
				modify(pw2+i,want=='('?+2:-2);
				modify(pw2+replace,want=='('?-2:+2);
				if (mn[1] >= 0)
				{
					swap(res[i],res[replace]);
					ans += min(cost[i][0], cost[i][1]);
					moveable[want=='('].erase(i);
					moveable[want==')'].erase(replace);
					moveable[want=='('].insert(replace);
					continue;
				}
				modify(pw2+i,want=='('?-2:+2);
				modify(pw2+replace,want=='('?+2:-2);
			}
		}
		if (cost[i][res[i]==')'] == INF)
		{
			printf("-1\n");
			return 0;
		}
		ans += cost[i][res[i]==')'];
		moveable[res[i]==')'].erase(i);
	}
	res[n]=0;
	printf("%lld\n%s\n",ans,res);
	return 0;
}