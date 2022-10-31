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

#define N 1000017
#define LOGN 20
int n, ojc[N], // input
pos[N], anc[LOGN+1][N]; // temp

int getPos(int u) {
   if (pos[u] == -1) pos[u] = getPos(ojc[u])+1;
   return pos[u];
}

void init(int root) {
   FORI(i,n) anc[0][i] = ojc[i];
   FORI(i,n) pos[i] = -1;
   pos[root] = 0;
   FORI(i,n) if (pos[i] == -1) getPos(i);
   FORI(i,LOGN) FORI(j,n) anc[i][j] = anc[i-1][anc[i-1][j]];
}

int lca (int u, int v) {
   if (pos[u] < pos[v]) swap(u,v);
   int diff = pos[u] - pos[v];
   REPD(k,LOGN,0) if ((1<<k) <= diff) {
      diff -= 1<<k;
      u = anc[k][u];
   }
   // teraz sa w tej samej odleglosci od roota
   if (u==v) return u;
   REPD(k,LOGN,0) if (anc[k][u] != anc[k][v]) {
      u = anc[k][u];
      v = anc[k][v];
   }
   return ojc[u];
}

int dist[N];

int main () {
   wez(q)
   n = 4;
   ojc[1] = -1;
   ojc[2] = ojc[3] = ojc[4] = 1;
   FOR(i,q) {
      wez(x)
      ojc[n+1] = x;
      ojc[n+2] = x;
      n += 2;
   }
   
   int v1 = 3, v2 = 2, diam = 2;
   init(1);
   dist[1] = 0;
   REP(i,2,n) dist[i] = 1 + dist[ojc[i]];
   REP(i,5,n) {
      int dist1 = dist[i] + dist[v1] - 2*dist[lca(i,v1)],
          dist2 = dist[i] + dist[v2] - 2*dist[lca(i,v2)];
      if (dist1 < dist2) {
         swap(v1,v2);
         swap(dist1,dist2);
      }
      // dist1 >= dist2
      if (dist1 > diam) {
         v2 = i;
         diam = dist1;
      }
      if (i % 2 == 0) pisz(diam);
   }
}