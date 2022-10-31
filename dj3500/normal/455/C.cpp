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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

struct UnionFind {
   vi tab, ile;

   UnionFind(int n) : // tworzy UF na 0, 1, ..., n-1
      tab(n), ile(n,1) {
      FOR(i,n) tab[i] = i;
   }

   int find(int a) {
      if (tab[a] == a) return a;
      return tab[a] = find(tab[a]);
   }

   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
      a = find(a), b = find(b);
      if (a==b) return 0;
      if (ile[a] <= ile[b]) {
         ile[b] += ile[a];
         tab[a] = b;
      } else {
         ile[a] += ile[b];
         tab[b] = a;
      }
      return 1;
   }
};

#define N 300008
vi adj[N];
int res;

int dfs (int v, int p) { // ile mam do najglebszego liscia
   vi zlisci;
   FOREACH(it,adj[v]) if (*it != p) {
      zlisci.pb(1 + dfs(*it, v));
   }
   if (zlisci.empty()) {
      return 0;
   }
   sort(zlisci.rbegin(), zlisci.rend());
   REMAX(res, SZ(zlisci) == 1 ? zlisci[0] : zlisci[0] + zlisci[1]);
   return zlisci[0];
}

int ans[N];

int zrob (int x, int y) {
   if (x < y) swap(x,y);
   // x >= y
   if (x-y > 2) return x;
   if (x-y == 2) {
      if (x % 2 == 1) return x + 1;
      else return x;
   }
   if (x-y == 1) {
      return x + 1;
   }
   // x == y
   if (x % 2 == 1) {
      return x + 2;
   } else {
      return x + 1;
   }
}

int zrob2 (int x, int y) {
   return max(max(x,y), (x+1) / 2 + (y+1) / 2 + 1);
}

int main () {
   REP(i,0,100) REP(j,0,100) if (zrob(i,j) != zrob2(i,j)) return 1;
   wez3(n,m,q)
   UnionFind uf(n+1);
   while (m--) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
      uf.unia(a,b);
   }
   FORI(i,n) if (i == uf.find(i)) {
      res = 0;
      dfs(i,-1);
      ans[i] = res;
   }
   while (q--) {
      wez(typ)
      if (typ == 1) {
         wez(x)
         x = uf.find(x);
         pisz(ans[x]);
      } else {
         wez2(a,b)
         a = uf.find(a);
         b = uf.find(b);
         if (a == b) continue;
         int x = ans[a], y = ans[b];
         uf.unia(a,b);
         ans[uf.find(a)] = zrob(x,y);
      }
   }
}