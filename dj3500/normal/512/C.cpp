// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cerr<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 100000 + 7; // max nodes
const int M = 100000 + 7; // max edges
typedef int T; // w razie zmiany na long long, zmieni te INF na 10^18
int nodes, src, dest, nedge;
int point[M], nxt[M], flow[M], capa[M];
int head[N], dist[N], Q[N], work[N];
 
void init (int _nodes, int _src, int _dest) {
   nodes = _nodes + 2; // na wszelki wypadek
   src = _src;
   dest = _dest;
   FOR(i,nodes) head[i] = -1;
   nedge = 0;
}

void addEdge(int u, int v, int c1, int c2 = 0) {
   point[nedge]=v, capa[nedge]=c1, flow[nedge]=0, nxt[nedge]=head[u], head[u]=(nedge++);
   point[nedge]=u, capa[nedge]=c2, flow[nedge]=0, nxt[nedge]=head[v], head[v]=(nedge++);
}

bool dinicBfs() {
   FOR(i,nodes) dist[i] = -1;
   dist[src] = 0;
   int szQ = 1;
   Q[0] = src;
   FOR(cl,szQ) {
      for (int k = Q[cl], i = head[k]; i >= 0; i = nxt[i]) {
         if (flow[i] < capa[i] && dist[point[i]] < 0) {
            dist[point[i]] = dist[k] + 1;
            Q[szQ++] = point[i];
         }
      }
   }
   return dist[dest] >= 0;
}

T dinicDfs (int x, T exp) {
   if (x == dest) return exp;
   T res = 0;
   for (int& i = work[x]; i >= 0; i = nxt[i]) {
      int v = point[i]; T tmp;
      if (flow[i] < capa[i] && dist[x]+1 == dist[v]
          && (tmp = dinicDfs(v, min(exp, (T)capa[i] - flow[i]))) > 0) {
         flow[i] += tmp;
         flow[i^1] -= tmp;
         res += tmp;
         exp -= tmp;
         if (0 == exp) break;
      }
   }
   return res;
}

T dinicFlow () {
   T res = 0;
   while (dinicBfs()) {
      FOR(i,nodes) work[i] = head[i];
      res += dinicDfs(src,INF);
   }
   return res;
}

int a[333];

vector<bool> sito (int m) { // m = max_inclusive
   vector<bool> pr(m+1,1);
   pr[0] = pr[1] = 0;
   for (int x = 2; x*x <= m; ++x) if (pr[x]) for (int y = x*x; y <= m; y += x) pr[y] = 0;
   return pr;
}

vi cur;
vi adj[N];
bool seen[N];

void dfs (int v) {
   if (seen[v]++) return;
   cur.pb(v);
   FOREACH(it,adj[v]) dfs(*it);
}

int main () {
   vector<bool> pr = sito(100000);
   
   wez(n)
   FORI(i,n) scanf("%d", a+i);
   
   init(n+5,0,n+1);
   FORI(i,n) {
      if (a[i] % 2 == 0) {
         addEdge(0, i, 2);
      } else {
         addEdge(i, n+1, 2);
      }
   }
   map<pii,int> number;
   FORI(i,n) if (a[i] % 2 == 0) FORI(j,n) if (a[j] % 2 == 1) if (pr[a[i] + a[j]]) {
      number[mp(i,j)] = nedge;
      addEdge(i, j, 1);
   }
   if (dinicFlow() != n) {
      printf("Impossible");
   } else {
      FOREACH(it,number) {
         if (flow[it->se] == 1) {
            int a = it->fi.fi, b = it->fi.se;
            adj[a].pb(b);
            adj[b].pb(a);
         }
      }
      vector<vi> res;
      FORI(i,n) if (!seen[i]) {
         cur.clear();
         dfs(i);
         res.pb(cur);
      }
      
      pisz(SZ(res));
      FOREACH(it,res) {
         printf("%d ", SZ(*it));
         FOREACH(jt,(*it)) printf("%d ", *jt);
      }
   }
}