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

#define N 2048000
int n;
char a[N],b[N];

int main()
{
	//freopen("data.in","r",stdin);

	gets(a);
	sscanf(a,"%d",&n);
	gets(a);
	gets(b);
	int d[2][2];
	CLEAR(d);
	REP(i,2*n)
	{
		++d[a[i]-'0'][b[i]-'0'];
	}
	int p1=0,p2=0;
	REP(move,n)
	{
		if (d[1][1]) ++p1,--d[1][1];
		else if (d[1][0]) ++p1,--d[1][0];
		else if (d[0][1]) --d[0][1];
		else --d[0][0];

		if (d[1][1]) ++p2,--d[1][1];
		else if (d[0][1]) ++p2,--d[0][1];
		else if (d[1][0]) --d[1][0];
		else --d[0][0];
	}
	printf("%s\n",p1==p2?"Draw":(p1>p2?"First":"Second"));
	return 0;
}