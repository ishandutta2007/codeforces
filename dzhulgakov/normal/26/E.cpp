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

#define N 1024
int n,w;
PII a[N];
int init[N];

int cnt[N];
int local[N];
bool verify(VI &res, int w)
{
	CLEAR(cnt);
	REP(i,SZ(res))
	{
		cnt[res[i]]++;
	}
	REP(i,n)
		if (init[i]*2!=cnt[i])
			return false;
	FILL(local,-1);
	int y = 0;
	REP(i,SZ(res))
	{
		if (local[res[i]]==-1)
		{
			local[res[i]] = y; 
		}
		else
		{
			y = local[res[i]]+1;
			local[res[i]]=-1;
		}
	}
	return y==w;
}

int main()
{
	//freopen("data.in","r",stdin);

	int n,w;
	scanf("%d%d",&n,&w);
	REP(i,n)
	{
		a[i].Y=i;
		scanf("%d",&a[i].X);
		init[i] = a[i].X;
	}
	sort(a,a+n);
	int mn,mx;
	if (n==1)
		mn=mx = a[0].X;
	else
	{
		mx = 0;
		REP(i,n)
			mx+=a[i].X;
		if (a[0].X == 1)
			mn = 1;
		else
			mn = 2;
	}
	if (w < mn || w > mx)
	{
		printf("No\n");
		return 0;
	}
	int sum=mx;
	printf("Yes\n");
	VI res;
	if (n==1)
		REP(i,2*a[0].X)
			res.pb(a[0].Y);
	else if (w >= a[0].X)
	{
		VI stack;
		REP(i,n)
			REP(j,a[i].X-(i==0))
				stack.pb(a[i].Y);
		res.pb(a[0].Y);
		while (mx>w)
		{
			res.pb(stack.back());
			res.pb(stack.back());
			stack.pop_back();
			mx--;
		}
		res.pb(a[0].Y);
		while (!stack.empty())
		{
			res.pb(stack.back());
			res.pb(stack.back());
			stack.pop_back();
		}
	}
	else
	{
		res.pb(a[0].Y);
		a[0].X--;
		a[1].X--;
		REPD(i,n) if (i>0)
			while (a[i].X > 0 && mx > w)
			{
				a[i].X--;
				mx--;
				res.pb(a[i].Y);
				res.pb(a[i].Y);
			}
		res.pb(a[0].Y);
		res.pb(a[1].Y);
		while (a[0].X > 0 && mx > w)
		{
			a[0].X--;
			mx--;
			res.pb(a[0].Y);
			res.pb(a[0].Y);
		}
		res.pb(a[1].Y);
		REPD(i,n)
			while (a[i].X > 0)
			{
				a[i].X--;
				res.pb(a[i].Y);
				res.pb(a[i].Y);
			}
	}
	//if (SZ(res) != 2*sum || !verify(res,w)) printf("BAD\n");
	REP(i,SZ(res))
		printf(" %d"+(i==0),res[i]+1);
	printf("\n");
	return 0;
}