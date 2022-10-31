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

#define N 10000
vector<pii> e;
vi adj[N];
void clear (int n) {
   e.clear();
   REP(i,0,n) adj[i].clear();
}
void add_edge (int a, int b) {
   adj[a].pb(SZ(e));
   adj[b].pb(SZ(e));
   e.pb(pii(a,b));
}
vi euler_undirected (int n) {
   int start = -1, odddeg = 0;
   REP(i,0,n) {
      if (SZ(adj[i]) & 1) odddeg++, start = i;
      else if (!adj[i].empty() && start == -1) start = i;
   }
   if (odddeg > 2) return vi();
   vector<bool> used(SZ(e),0); // zuzycie krawedzi
   vi stack, res, ktora(n+1,0); // ktora krawedz teraz bedzie przetwarzana
   stack.pb(start);
   while (!stack.empty()) {
      int v = stack.back();
      while (ktora[v] < SZ(adj[v]) && used[adj[v][ktora[v]]]) ++ktora[v]; // przewin zuzyte
      if (ktora[v] == SZ(adj[v])) { // wycofaj sie
         stack.pop_back();
         res.pb(v);
      } else {
         int ed = adj[v][ktora[v]];
         int w = e[ed].fi == v ? e[ed].se : e[ed].fi;
         used[ed] = 1;
         stack.pb(w);
      }
   }
   if (count(ALL(used),0)) return vi(); // graf niespojny
   return res;
}

vi tiles[8][8];

int main () {
   wez(n);
   clear(6);
   FORI(i,n) {
      wez2(a,b)
      add_edge(a,b);
      tiles[a][b].pb(i);
   }
   vi v = euler_undirected(6);
   if (v.empty()) {
      printf("No solution\n");
      return 0;
   }
   FOR(i,SZ(v)-1) {
      int a = v[i], b = v[i+1];
      if (tiles[a][b].empty()) {
         printf("%d -\n", tiles[b][a].back());
         tiles[b][a].pop_back();
      } else {
         printf("%d +\n", tiles[a][b].back());
         tiles[a][b].pop_back();
      }
   }
}