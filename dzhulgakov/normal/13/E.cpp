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

#define BS 320
#define N 111000
int n,m;
int a[N];
int speed[N],spcnt[N];
bool invalid[N];

inline void recalc(int g)
{
	invalid[g]=false;
	int st = g*BS;
	int end = min(st+BS,n);
	for (int i = end-1; i >= st; i--)
	{
		if (i+a[i] < end)
		{
			spcnt[i]=1+spcnt[i+a[i]];
			speed[i]=a[i]+speed[i+a[i]];
		}
		else
		{
			speed[i]=0;
			spcnt[i]=0;
		}
	}
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d",&n,&m);
	REP(i,n/BS+1)
		invalid[i]=true;
	REP(i,n)
		scanf("%d",a+i);
	REP(step,m)
	{
		int cmd,x;
		scanf("%d%d",&cmd,&x);
		x--;
		if (cmd==0)
		{
			int b;
			scanf("%d",&b);
			a[x]=b;
			invalid[x/BS]=true;
		}
		else
		{
			int res = 1;
			while(1)
			{
				if (invalid[x/BS])
					recalc(x/BS);
				res += spcnt[x];
				x += speed[x];
				if (x+a[x] >= n)
					break;
				res++;
				x+=a[x];
			}
			printf("%d %d\n",x+1,res);
		}
	}
	return 0;
}