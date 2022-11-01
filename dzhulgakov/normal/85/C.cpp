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
int n,k;
int key[N];
PII a[N];
PII b[N];
int mn[N],mx[N];
double ans[N],ansr[N];

void dfs1(int v)
{
	mn[v]=mx[v]=key[v];
	if (a[v].first != -1)
	{
		dfs1(a[v].first);
		dfs1(a[v].second);
		mn[v] = min(mn[v], mn[a[v].first]);
		mx[v] = max(mx[v], mx[a[v].second]);
	}
}

void dfs2(int v, int left, int right, int level = 0, double ex = 0)
{
	if (a[v].first == -1)
	{
		FOR(i,left,right)
		{
			ans[i] = ex;
		}
		return;
	}
	int mid = lower_bound(b+left,b+right+1,PII(key[v],0)) - b;
	dfs2(a[v].first, left, mid-1, level+1, (ex*level + mn[a[v].second]) / (double)(level+1));
	dfs2(a[v].second, mid, right, level+1, (ex*level + mx[a[v].first]) / (double)(level+1));
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	FILL(a,-1);
	int root;
	REP(i,n)
	{
		int p;
		scanf("%d%d",&p,&key[i]);
		if (p==-1)
			root = i;
		else
		{
			p--;
			if (a[p].first == -1)
				a[p].first = i;
			else
				a[p].second = i;
		}
	}
	REP(i,n) if (a[i].first != -1)
		if (key[a[i].first] > key[a[i].second])
			swap(a[i].first, a[i].second);
	scanf("%d",&k);
	REP(i,k)
	{
		scanf("%d",&b[i].first);
		b[i].second = i;
	}
	sort(b,b+k);
	dfs1(root);
	dfs2(root,0,k-1);
	REP(i,k)
		ansr[b[i].second] = ans[i];
	REP(i,k)
		printf("%.12lf\n",ansr[i]);
	return 0;
}