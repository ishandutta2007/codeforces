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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 2020
int d[N][N];
ll odl[N][N];

void bfs1 (int n, int source, vi *adj) {
   deque<int> q;
   q.pb(source);
   FOR(i,n) odl[source][i] = -1;
   odl[source][source] = 0;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOREACH(it,adj[v]) if (odl[source][*it] == -1) {
         odl[source][*it] = odl[source][v] + d[v][*it];
         //DBG(mp(source,*it))DBG(odl[source][*it])
         q.pb(*it);
      }
   }
}

void zle () { printf("NO"); exit(0); }

vi adj[N];
int cnt = 0;
void add (int a, int b) {
   //DBG(mp(a,b))
   adj[a].pb(b);
   adj[b].pb(a);
   ++cnt;
}

void build (const vi &v, int x) { // v + {x}
   if (SZ(v) == 0) {
      // nic
   } else {
      pii mini;
      mini.fi = INF;
      FOREACH(y,v) {
         REMIN(mini, mp(d[x][*y], *y));
      }
      int y = mini.se;
      //DBG(y)
      add(x, y);
      vi v1, v2;
      FOREACH(z,v) if (*z != y) {
         if (d[*z][x] < d[*z][y]) v1.pb(*z);
         else v2.pb(*z);
      }
      build(v1, x);
      build(v2, y);
   }
}

int main () {
   wez(n)
   FOR(i,n) FOR(j,n) scanf("%d", &d[i][j]);
   FOR(i,n) if (d[i][i] != 0) zle();
   FOR(i,n) FOR(j,i) {
      if (d[i][j] != d[j][i]) zle();
      if (d[i][j] == 0) zle();
   }
   vi v;
   FORI(i,n-1) v.pb(i);
   build(v, 0);
   if (cnt != n-1) zle();
   FOR(i,n) bfs1(n, i, adj);
   FOR(i,n) FOR(j,n) if (d[i][j] != odl[i][j]) {
      //DBG(mp(i,j));
      //DBG(d[i][j])DBG(odl[i][j]);
      zle();
   }
   printf("YES");
}