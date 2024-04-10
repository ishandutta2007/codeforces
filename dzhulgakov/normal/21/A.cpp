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

int n,p;
char a[256];
bool res;

void read(char stop1, char stop2=0, int mn=1, int mx=16)
{
	int i;
	for (i = 0; a[p] && a[p]!=stop1 && a[p]!=stop2 && i<mx; i++,p++)
		if (!('0'<=a[p]&&a[p]<='9' || 'a'<=a[p]&&a[p]<='z' || 'A'<=a[p]&&a[p]<='Z' || a[p]=='_'))
		{
			res=false;
			return;
		}
	if (i<mn)
	{
		res=false;
		return;
	}
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%s",a);
	n=strlen(a);
	res=true;
	p=0;
	read('@');
	if (res && a[p++]=='@')
	{
		int ps = p;
		while (1)
		{
			read('.','/');
			if (!res) break;
			if (a[p]=='.')
			{
				p++;
				continue;
			}
			if (a[p]==0 || a[p]=='/')
				break;
			res=false;
			break;
		}
		if (res && p-ps <= 32)
		{
			if (a[p]=='/')
			{
				p++;
				read(0);
			}
		}
		else
			res=false;
	}
	else
		res=false;
	printf("%s\n",res?"YES":"NO");
	return 0;
}