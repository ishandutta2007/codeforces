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

int n;
int a[128],d[128];
bool mark[128];
set<int> s1,s2;

void dfs(int i)
{
	if (mark[i]) return;
	mark[i]=true;
	s1.insert(i);
	s2.insert(a[i]);
	REP(j,n) if (abs(i-j) == d[i] || abs(i-j) == d[j])
		dfs(j);
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	REP(i,n)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	REP(i,n)
	{
		scanf("%d",d+i);
	}
	CLEAR(mark);
	bool res = true;
	REP(i,n) if (!mark[i])
	{
		s1.clear();
		s2.clear();
		dfs(i);
		if (s1!=s2) res=false;
	}
	printf("%s\n",res?"YES":"NO");
	return 0;
}