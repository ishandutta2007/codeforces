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

int n,mx,reg,cur;
vector<pair<PII,int> > a;

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&mx,&reg);
	cur = mx;
	REP(i,n)
	{
		int pw, d;
		scanf("%d%d",&pw,&d);
		a.push_back(make_pair(PII(d,pw),i));
	}
	SORT(a);
	int minus = 0;
	VPII ans;
	FOR(day,0,2048)
	{
		cur -= minus;
		cur += reg;
		cur = min(cur,mx);
		if (cur <= 0)
		{
			printf("YES\n");
			printf("%d %d\n",day,SZ(ans));
			REP(i,SZ(ans))
				printf("%d %d\n",ans[i].X, ans[i].Y+1);
			return 0;
		}
		for (int i = SZ(a)-1; i >= 0; i--)
		{
			if (a[i].X.second*mx >= cur*100)
			{
				minus += a[i].X.first;
				ans.push_back(PII(day, a[i].second));
				a.erase(a.begin()+i);
				break;
			}
		}
	}
	printf("NO\n");
	return 0;
}