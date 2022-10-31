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
#define INF 1000000000
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

struct UnionFind {
   vi tab, ile;

   UnionFind(int n) : // tworzy UF na 0, 1, ..., n-1
      tab(n), ile(n,1) {
      FOR(i,n) tab[i] = i;
   }

   int find(int a) {
      if (tab[a] == a) return a;
      return a = find(tab[a]);
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

// dwacol(n,adj) bierze graf o wierzcholkach 1..n i go dwukoloruje
// jesli sie nie udalo, zamiast kolorowania zwraca pusty wektor
vi dwacol (int n, vi *adj) {
   vi ans(n+1,2);
   FORI(i,n) {
      if (ans[i] != 2) continue;
      deque<pii> q;
      q.pb(mp(i,0));
      while (!q.empty()) {
         int v = q.front().fi, kol = q.front().se;
         q.pop_front();
         if (ans[v] == 2) {
            ans[v] = kol;
            FOREACH(it,adj[v]) q.pb(mp(*it,1-kol));
         } else if (ans[v] != kol) return vi();
      }
   }
   return ans;
}

vi adj[105];

int main () {
   wez2(n,m)
   vector<pii> edges;
   UnionFind uf(n+2);
   while(m--) {
      wez3(a,b,c)
      if (c == 1) {
         uf.unia(a,b);
      } else {edges.pb(mp(a,b));}
   }
   
   FOREACH(ed,edges) {
      int a = uf.find(ed->fi), b = uf.find(ed->se);
      adj[a].pb(b);
      adj[b].pb(a);
   }
   vi kol = dwacol(n,adj);
   if (kol.empty()) {
      printf("Impossible");
   } else {
      vi res;
      FORI(v,n) {
         if (kol[uf.find(v)]) {
            res.pb(v);
         }
      }
      pisz(SZ(res));
      FOREACH(x,res) printf("%d ", *x);
   }
}