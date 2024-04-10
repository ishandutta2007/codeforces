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

int n,m;
typedef struct {
	int n4,n7,n47,n74;
	int delayed;
} T;

int init[1024000];
const int LIMIT = (1<<21);
T a[LIMIT];

inline void change(int v)
{
	swap(a[v].n4,a[v].n7);
	swap(a[v].n47,a[v].n74);
	a[v].delayed ^= 1;
}

inline void down(int v)
{
	if (!a[v].delayed) return;
	a[v].delayed = 0;
	if (v*2 < LIMIT) change(v*2);
	if (v*2+1 < LIMIT) change(v*2+1);
}

inline void up(int v)
{
	down(v);
	a[v].n4 = a[v*2].n4 + a[v*2+1].n4;
	a[v].n7 = a[v*2].n7 + a[v*2+1].n7;
	a[v].n47 = max(a[v*2].n47 + a[v*2+1].n7, a[v*2].n4 + a[v*2+1].n47);
	a[v].n74 = max(a[v*2].n74 + a[v*2+1].n4, a[v*2].n7 + a[v*2+1].n74);
}

void build(int v, int l, int r)
{
	if (l==r)
	{
		if (init[l]==4)
			a[v].n4 = 1;
		else
			a[v].n7 = 1;
		a[v].n47 = a[v].n74 = 1;
	}
	else
	{
		int mid = (l+r)/2;
		build(v*2,l,mid);
		build(v*2+1,mid+1,r);
		up(v);
	}
}

int cl,cr;

void go(int v, int l, int r)
{
	if (r < cl || cr < l) return;
	if (cl <= l && r <= cr)
	{
		change(v);
		return;
	}
	int mid = (l+r)/2;
	down(v);
	go(v*2,l,mid);
	go(v*2+1,mid+1,r);
	up(v);
}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	CLEAR(a);
	REP(i,n)
	{
		char c;
		do c = getc(stdin);
		while (c!='4'&&c!='7');
		init[i]=c-'0';
	}

	//REP(i,n) init[i]=i%2 ? 4 : 7;

	build(1,0,n-1);
	REP(i,m)
	{
		char cmd[256];
		scanf("%s",cmd);
		//if (i%2 == 0) strcpy(cmd,"count"); else cmd[0]=0;
		if (strcmp(cmd,"count")==0)
			printf("%d\n",a[1].n47);
		else
		{
			scanf("%d%d",&cl,&cr);
			//cl = rand()%n+1; cr = rand()%n+1; if (cl>cr) swap(cl,cr);
			--cl,--cr;
			go(1,0,n-1);
		}
	}
	return 0;
}