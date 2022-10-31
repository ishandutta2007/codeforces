#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1010000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 3000+9; // max nodes
const int M = 1000000+5; // max edges
 
int nodes, nedge, src, dest;
int point[M], next[M], flow[M], capa[M], cost[M], skad[M];
int head[N], dist[N], expand[N], prev[N], edge[N];
bool changed[N];
 
void init (int _nodes, int _src, int _dest) {
	nodes = _nodes;
	src = _src;
	dest = _dest;
	nedge = 0;
	FOR(i,nodes) head[i] = -1;
}

void addEdge (int u, int v, int c, int w) {
	skad[nedge] = u, point[nedge]=v, capa[nedge]=c, cost[nedge]=w,  flow[nedge]=0, next[nedge]=head[u], head[u]=(nedge++);
	skad[nedge] = v, point[nedge]=u, capa[nedge]=0, cost[nedge]=-w, flow[nedge]=0, next[nedge]=head[v], head[v]=(nedge++);
}

pii ford() {
	int mflow = 0, mcost = 0;
	while (1) {
		FOR(i,nodes) dist[i] = INF, prev[i] = -1, changed[i] = 0;
		dist[src] = 0;
		changed[src] = 1;
		expand[src] = INF;
		while (1) {
			bool ok = 1;
			FOR(i,nodes) if (changed[i]) {
				changed[i] = 0;
				for (int k = head[i]; k>=0; k=next[k]) {
					if (flow[k] < capa[k] && dist[i]+cost[k] < dist[point[k]]) {
						dist[point[k]] = dist[i]+cost[k];
						changed[point[k]] = 1;
						prev[point[k]] = i;
						edge[point[k]] = k;
						expand[point[k]] = min(expand[i], capa[k]-flow[k]);
						ok = 0;
					}
				}
			}
			if (ok) break;
		}
		if (prev[dest] < 0) break;
		int d = expand[dest];
		mflow += d;
		mcost += d*dist[dest];
		for (int k = dest; k != src; k = prev[k]) {
			flow[edge[k]] += d;
			flow[edge[k]^1] -= d;
		}
   }
   return mp(mflow,mcost);
}

#define MM 1005
int s[MM], t[MM], c[MM];

int main () {
   wez2(n,k)
   set<int> poczatkis;
   FORI(i,n) {
      scanf("%d %d %d",s+i,t+i,c+i);
      poczatkis.insert(s[i]);
   }
   vi poczatki(ALL(poczatkis));
   init(3005, 0, 2002);
   addEdge(0, 1, k, 0);
   FORI(i,n) {
      addEdge(1, 2*i, 1, 0);
      addEdge(2*i, 2*i+1, 1, -c[i]);
      addEdge(2*i+1, 2002, 1, 0);
   }
   FOR(u,SZ(poczatki)) {
      FORI(i,n) if (s[i] == poczatki[u]) addEdge(2003+u, 2*i, 1, 0);
      if (u != 0) addEdge(2003+u-1, 2003+u, INF, 0);
   }
   FORI(i,n) {
      int ind = lower_bound(ALL(poczatki), s[i]+t[i]) - poczatki.begin();
      if (ind != SZ(poczatki)) addEdge(2*i+1, 2003+ind, 1, 0);
   }
   ford();
   FORI(i,n) FOR(u,nedge) if (skad[u] == 2*i && point[u] == 2*i+1) printf("%d ",flow[u]);
}