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

#define N 111000
int n,k,h,v[N],m[N];
pair<PII,int> mord[N];
int res[N],cur[N];

bool go(double tm)
{
	int i = 0;
	REP(j,k)
	{
		while (i<n && (j+1)*(double)h/(double)v[mord[i].second] > tm) ++i;
		if (i==n) return false;
		cur[j] = mord[i].second;
		++i;
	}
	return true;
}

int main()
{
	//freopen("a.in","r",stdin);

	scanf("%d%d%d",&n,&k,&h);
	REP(i,n)
	{
		scanf("%d",m+i);
	}
	REP(i,n)
	{
		scanf("%d",v+i);
		mord[i]=make_pair(PII(m[i],v[i]),i);
	}
	sort(mord,mord+n);
	double left = 0, right = k*(double)h*2;
	REP(step,100)
	{
		double mid = (left+right)/2;
		if (go(mid))
		{
			memcpy(res,cur,sizeof res);
			right = mid;
		}
		else
			left = mid;
	}
	REP(i,k) printf(" %d"+(i==0),res[i]+1);
	printf("\n");
	return 0;
}