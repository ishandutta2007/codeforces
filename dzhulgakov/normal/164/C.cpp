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
#define LINF 10000000000LL
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

int n,k;
pair<PII,PII> a[1024];
int id[1024];

class MinCostMaxFlow { public:
	int n,s,t;
	struct Edge	{
		int end,cap;
		LL cost;
		int next;
		Edge(int e, int ca, LL co, int ne):
			end(e), cap(ca), cost(co), next(ne) {} };
	VI first, prev;
	vector<LL> dist,p;
	vector<Edge> a;
	MinCostMaxFlow(int nn, int ss, int tt): n(nn), s(ss), t(tt) { first.assign(n,-1); }
	int add(int v, int u, int cap, int cost) {
		a.pb(Edge(u,cap,cost,first[v])); first[v] = SZ(a)-1;
		a.pb(Edge(v,0,-cost,first[u])); first[u] = SZ(a)-1;
		return SZ(a)-2;	}
	void initDist() {
		queue<int> q; vector<bool> added(n,false); vector<int> updated(n,0);
		dist.assign(n,LINF); dist[s]=0; q.push(s); added[s]=true; prev.assign(n,-1);
		while (!q.empty()) {
			int v = q.front(); q.pop(); added[v]=false;
			for (int e = first[v]; e!=-1; e=a[e].next)
				if (a[e].cap && dist[a[e].end]>dist[v]+a[e].cost){
					dist[a[e].end] = dist[a[e].end] > dist[v]+a[e].cost;
					if (!added[a[e].end]) {
						prev[a[e].end]=e; added[a[e].end]=true;
						q.push(a[e].end); }
				} }
		p=dist;	}
	bool findPath(int s, int t)	{
		set<pair<LL,int> > q;
		dist.assign(n,LINF); dist[s]=0; q.insert(PII(0,s)); prev.assign(n,-1);
		while (!q.empty()) {
			int v = q.begin()->second; q.erase(q.begin());
			for (int e = first[v]; e!=-1; e=a[e].next)
				if (a[e].cap && dist[a[e].end] >
						dist[v]+a[e].cost+p[v]-p[a[e].end]) {
					q.erase(pair<LL,int>(dist[a[e].end], a[e].end));
					dist[a[e].end] = dist[v]+a[e].cost+p[v]-p[a[e].end];
					prev[a[e].end] = e;
					q.insert(pair<LL,int>(dist[a[e].end], a[e].end));
				} }
		return dist[t] < LINF; }
	void augment(int s, int t, pair<int,LL> &res, int cap=INF) {
		for (int v=t; v!=s; v=a[prev[v]^1].end) cap = min(cap, a[prev[v]].cap);
		res.first += cap; res.second += cap*(dist[t]+p[t]-p[s]);
		for (int v=t; v!=s; v=a[prev[v]^1].end)
			a[prev[v]].cap-=cap, a[prev[v]^1].cap+=cap;
		REP(i,n) p[i]+=dist[i];	}
	pair<int,LL> build() {
		initDist();
		pair<int,LL> res(0,0);
		while (findPath(s,t)) augment(s,t,res);
		return res;	}
};

int main()
{
	scanf("%d%d",&n,&k);
	REP(i,n)
	{
		scanf("%d%d%d",&a[i].first.X,&a[i].first.Y,&a[i].second.first);
		a[i].second.second = i;
	}
	sort(a,a+n);
	MinCostMaxFlow mcmf(2*n+2,2*n,2*n+1);
	mcmf.add(mcmf.s,0,k,0);
	REP(i,n-1)
		mcmf.add(i,i+1,k,0);
	mcmf.add(n-1,mcmf.t,k,0);
	REP(i,n)
	{
		int fn = a[i].first.X + a[i].first.Y;
		int j = i;
		while (j < n && a[j].first.X < fn) ++j;
		if (j == n)
			j = mcmf.t;
		mcmf.add(i+n,j,1,0);
		id[a[i].second.second] = mcmf.add(i,i+n,1,-a[i].second.first)^1;
	}
	mcmf.build();
	REP(i,n)
		printf(" %d"+(i==0),mcmf.a[id[i]].cap);
	printf("\n");
	return 0;
}