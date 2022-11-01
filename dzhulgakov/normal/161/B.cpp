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
int n,k;
VPII a,b;
VPII res[N];
bool has[N];

int main()
{
	//freopen(".in","r",stdin);

	scanf("%d%d",&n,&k);
	REP(i,n)
	{
		int type,w;
		scanf("%d%d",&w,&type);
		if (type == 1)
			a.pb(PII(w,i));
		else
			b.pb(PII(w,i));
	}
	SORT(a);
	SORT(b);
	REP(i,k)
	{
		if (!a.empty())
		{
			res[i].pb(a.back());
			has[i]=true;
			a.pop_back();
		}
		else
		{
			has[i]=false;
			res[i].pb(b.back());
			b.pop_back();
		}
	}
	REP(i,SZ(a))
		res[k-1].pb(a[i]);
	REP(i,SZ(b))
		res[k-1].pb(b[i]);
	LL sum = 0;
	REP(i,k)
	{
		SORT(res[i]);
		REP(j,SZ(res[i]))
			sum += 2LL*res[i][j].first;
		if (has[i])
			sum -= res[i][0].first;
	}
	cout << (sum/2) << "." << (sum%2 ? 5 : 0) << endl;
	REP(i,k)
	{
		cout << SZ(res[i]);
		REP(j,SZ(res[i])) cout << " " << (res[i][j].second+1);
		cout << endl;
	}
	return 0;
}