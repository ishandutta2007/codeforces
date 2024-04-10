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
#define INF 1010000100
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

// bierze graf skierowany waony o wierzcholkach 1..n. output:
// dist[i] - odleglosc od src
// parent[i] - ojciec w drzewie najkrotszych odleglosci

#define MAXN 100006
int dist[MAXN], parent[MAXN];

struct comp {
   inline bool operator () (int v, int w) const {
      if (dist[v] != dist[w]) return dist[v] < dist[w];
      return v < w;
   }
};

vi badtimes[MAXN];

void dijkstra (int n, vector<pii> *adj, int src) {
   FORI(i,n) {
      dist[i] = INF;
      parent[i] = -1;
   }
   dist[src] = 0;
   set<int,comp> q;
   q.insert(src);
   while (!q.empty()) {
      int v = *(q.begin());
      q.erase(q.begin());
      
      if (v == n) return;
      
      if (binary_search(ALL(badtimes[v]), dist[v])) {
         dist[v]++;
         q.insert(v);
         continue;
      }
      
      FOREACH(it,adj[v]) {
         int d = dist[v] + it->se, w = it->fi;
         if (d < dist[w]) {
            q.erase(w);
            dist[w] = d;
            q.insert(w);
            parent[w] = v;
         }
      }
   }
}

vector<pii> adj[MAXN];

int main () {
   wez(n)
   TESTS {
      wez3(a,b,c)
      adj[a].pb(mp(b,c));
      adj[b].pb(mp(a,c));
   }
   FORI(i,n) {
      wez(ile)
      while(ile--) {
         wez(u)
         badtimes[i].pb(u);
      }
   }
   dijkstra(n,adj,1);
   if (dist[n] == INF) pisz(-1);
   else pisz(dist[n]);
}