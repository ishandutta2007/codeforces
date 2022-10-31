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
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define MAXV 1024
namespace hk {
int n,m;
vi adj[MAXV];
int para[MAXV], dist[MAXV];

bool bfs() {
   deque<int> q;
   FORI(v,n) {
      if (!para[v]) {
         dist[v]=0;
         q.pb(v);
      } else dist[v] = INF;
   }
   dist[0] = INF;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOR(i,SZ(adj[v])) {
         int u = adj[v][i];
         if (dist[para[u]] == INF) {
            dist[para[u]] = dist[v]+1;
            q.pb(para[u]);
         }
      }
   }
   return dist[0] != INF;
}

bool dfs (int v) {
   if (!v) return 1;
   FOR(i,SZ(adj[v])) {
      int u = adj[v][i];
      if (dist[para[u]] == dist[v]+1) {
         if (dfs(para[u])) {
            para[u]=v;
            para[v]=u;
            return 1;
         }
      }
   }
   dist[v]=INF;
   return 0;
}

// maximum bipartite matching w czasie O(sqrt(V) * E)
// wierzchoki z pierwszej czci maj mie nry 1..n, z drugiej - n+1..n+m
// przed wywoaniem naley ustawi zmienne: n,m,adj (adj wystarczy mie wypenione dla wierzchokw 1..n) (adj[0] powinno byc puste)
// oraz sta MAXV = maksymalne n+m

int matching () {
   FOR(i,n+m+1) para[i]=0;
   int w = 0;
   while (bfs()) FORI(v,n) if (!para[v]) if (dfs(v)) ++w;
   return w;
}
};


#define N 512
bool g[N][N];

int main () {
   wez2(n,mm)
   vector<pii> edges;
   FOR(k,mm) {
      wez2(a,b)
      g[a][b] = 1;
      edges.pb(mp(a,b));
   }
   int ans = INF;
   REP(c,1,n) {
      int res = 0;
      
      REP(x,1,n) if (x != c) {
         if (!g[x][c]) ++res;
         if (!g[c][x]) ++res;
      }
      if (!g[c][c]) ++res;
      
      hk::n = hk::m = n;
      REP(x,1,n) hk::adj[x].clear();
      int ones = 0;
      FOREACH(it,edges) {
         if (it->fi != c && it->se != c) {
            hk::adj[it->fi].pb(n + it->se);
            ++ones;
         }
      }
      
      res += ones + (n-1) - 2 * hk::matching();
      
      REMIN(ans,res);
   }
   pisz(ans);
}