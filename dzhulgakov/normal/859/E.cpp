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
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <stack>

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
//const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 222000
#define MOD 1000000007
int n,m;
bool appears[N];
bool full[N];
bool withempty[N];
bool dot[N];
int cnt[N];

// Disjoint sets
int p[N],r[N];
int getset(int v) {	return p[v]==v ? v : (p[v]=getset(p[v])); }
void mergeset(int v, int u) { if (r[v]<r[u]) p[v]=u; else {p[u]=v; r[v]+=r[u]==r[v]; } }

int main()
{
	//freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&m);
	n=m*2;
	REP(i,n) p[i]=i;
	CLEAR(r);

	CLEAR(full);
	CLEAR(appears);
	CLEAR(dot);

	REP(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		full[x] = true;
		appears[x]=appears[y]=true;
		mergeset(getset(x),getset(y));
		if (x==y) dot[x]=true;
	}
	CLEAR(cnt);
	CLEAR(withempty);
	REP(i,n) if (appears[i])
	{
		int v = getset(i);
		cnt[v]++;
		if (!full[i]) withempty[v]=true;
		if (dot[i]) dot[v]=true;
	}
	LL res = 1;
	REP(i,n) if (cnt[i])
	{
		//fprintf(stderr,"= %d\n",cnt[i]);
		int t = withempty[i] ? cnt[i] : (dot[i] ? 1 : 2);
		res = (res*t)%MOD;
	}
	printf("%d\n",(int)(res%MOD));
	return 0;
}