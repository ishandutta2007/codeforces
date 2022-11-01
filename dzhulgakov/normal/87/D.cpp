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
int p[N],r[N],cnt[N];
int getset(int v) {	return p[v]==v ? v : (p[v]=getset(p[v])); }
void mergeset(int v, int u) { if (r[v]<r[u]) p[v]=u, cnt[u]+=cnt[v]; else {p[u]=v; r[v]+=r[u]==r[v]; cnt[v]+=cnt[u]; } }

int n;
PII a[N],b[N];
VI adj[N];
int gli;
int chsum[N],rootedge[N],iter[N];
LL d[N];
VI comp;

void dfs(int v)
{
	comp.pb(v);
	iter[v] = gli;
	chsum[v] = cnt[v];
	REP(i,SZ(adj[v]))
	{
		int e = adj[v][i];
		if (e == rootedge[v]) continue;
		int vv = v==a[e].X ? a[e].Y : a[e].X;
		rootedge[vv] = e;
		dfs(vv);
		chsum[v] += chsum[vv];
	}
}

int main()
{
	//freopen("d.in","r",stdin);
	scanf("%d",&n);
	REP(i,n-1)
	{
		scanf("%d%d%d",&a[i].X,&a[i].Y,&b[i].first);
		a[i].X--;
		a[i].Y--;
		b[i].second = i;
	}
	sort(b,b+n-1);
	FILL(chsum,-1);
	FILL(rootedge,-1);
	FILL(iter,-1);
	REP(i,n)
	{
		cnt[i]=1;
		p[i]=i;
		r[i]=0;
	}
	for (int i1 = 0; i1 < n-1; )
	{
		int ii = i1;
		VI cur;
		while (i1 < n-1 && b[i1].first == b[ii].first) cur.pb(b[i1++].second);
		REP(j,SZ(cur))
		{
			a[cur[j]].X = getset(a[cur[j]].X);
			a[cur[j]].Y = getset(a[cur[j]].Y);
			adj[a[cur[j]].X].clear();
			adj[a[cur[j]].Y].clear();
		}
		REP(j,SZ(cur))
		{
			adj[a[cur[j]].X].pb(cur[j]);
			adj[a[cur[j]].Y].pb(cur[j]);
		}
		gli = i1;
		REP(j,SZ(cur)) REP(jj,2)
		{
			int v = jj ? a[cur[j]].X : a[cur[j]].Y;
			if (iter[v] == gli) continue;
			comp.clear();
			dfs(v);
			REP(ii,SZ(comp))
			{
				int ver = comp[ii];
				if (ver == v) continue;
				d[rootedge[ver]] = chsum[ver]*(LL)(chsum[v]-chsum[ver]);
			}
		}
		REP(j,SZ(cur))
		{
			int x = getset(a[cur[j]].X);
			int y = getset(a[cur[j]].Y);
			if (x!=y)
				mergeset(x,y);
		}
	}
	LL mx = 0;
	REP(i,n-1)
		mx = max(mx,d[i]);
	VI lst;
	REP(i,n-1)
		if (d[i]==mx)
			lst.pb(i);
	cout << mx*2 << " " << SZ(lst) << endl;
	REP(i,SZ(lst))
	{
		if (i) cout << " ";
		cout << (lst[i]+1);
	}
	cout<<endl;
	return 0;
}