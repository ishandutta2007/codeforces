#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:16000000")
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

#define N 1024000
int n1,n2,a1[N],a2[N],id1[N],id2[N];

int main()
{
	scanf("%d%d",&n1,&n2);
	FILL(id1,-1);
	FILL(id2,-1);
	REP(i,n1)
	{
		scanf("%d",a1+i);
		id1[a1[i]]=i;
	}
	REP(i,n2)
	{
		scanf("%d",a2+i);
		id2[a2[i]]=i;
	}
	deque<LL> q;
	int res = 0;
	REP(i,n1*2)
	{
		int c = a1[i%n1];
		LL x = id2[c];
		if (x == -1)
			q.clear();
		else
		{
			if (!q.empty())
			{
				x += q.front()/n2*n2;
				while (x <= q.front())
					x += n2;
				while (!q.empty() && x-q.back() >= n2)
					q.pop_back();
			}
			q.push_front(x);
			while (SZ(q) > n1) q.pop_back();
			res = max(res,SZ(q));
		}
	}
	printf("%d\n",res);
	return 0;
}