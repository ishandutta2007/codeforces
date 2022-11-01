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
char a[11000];
char *p;
VI res;

bool eat(char * s)
{
	if (strncmp(p,s,strlen(s))==0)
	{
		p += strlen(s);
		return true;
	}
	return false;
}

void skip()
{
	eat("<tr>");
	eat("</tr>");
}

void go()
{
	int cur = 0;
	eat("<table>");
	while (true)
	{
		skip();
		if (eat("</table>")) break;
		if (eat("<td>"))
		{
			cur++;
			if (!eat("</td>"))
			{
				go();
				eat("</td>");
			}
		}
	}
	skip();
	res.push_back(cur);
}

int main()
{
	//freopen("input.txt","r",stdin);
	n = 0;
	while (gets(a+n) != NULL)
	{
		n += strlen(a+n);
		while (n && a[n-1] == '\n') n--;
	}
	a[n]=0;
	p = a;
	go();
	SORT(res);
	REP(i,SZ(res)) printf(" %d"+(i==0), res[i]);
	printf("\n");
	return 0;
}