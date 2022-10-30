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

template <int N, int LOGN>
struct LCA {
   int n, root, pos[N], anc[LOGN+1][N], *ojc;

   int getPos(int u) {
      if (pos[u] == -1) pos[u] = getPos(ojc[u])+1;
      return pos[u];
   }

   // n - liczba wierzcholkow w drzewie, numerowanych 1..n
   // ojc - tablica: ojc[i] to ojciec wierzcholka i
   // root - korzen drzewa
   LCA(int _n, int _root, int *_ojc):
      n(_n), root(_root), ojc(_ojc) {
      FORI(i,n) anc[0][i] = ojc[i];
      FORI(i,n) pos[i] = -1;
      pos[root] = 0;
      FORI(i,n) if (pos[i] == -1) getPos(i);
      FORI(i,LOGN) FORI(j,n) anc[i][j] = anc[i-1][anc[i-1][j]];
   }

   int operator() (int u, int v) {
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
};

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


#define MAXN 100007
int n;               // input
vi adja[MAXN];        // input
vector<pii> mosty;   // output - lista par wierzcholkow, krawedz miedzy ktorymi jest mostem
bool art[MAXN];      // output - art[v]==1 iff v jest pktem artykulacji
int czas, wej[MAXN]; // temp

int bridgeArtGo (int v, int p) {
   int k = wej[v] = ++czas;
   FOREACH(it,adja[v]) if (*it != p) k = min(k, wej[*it] ? wej[*it] : bridgeArtGo(*it,v));
   if (wej[p] <= k) art[p] = 1;
   if (wej[p] < k) mosty.pb(mp(min(v,p),max(v,p)));
   return k;
}
void bridgeArt() {
   mosty.clear();
   czas = 0;
   FORI(i,n) wej[i] = art[i] = 0;

   FORI(i,n) if (!wej[i]) {
      wej[i] = ++czas;
      int c = 0;
      FOREACH(it,adja[i]) if (!wej[*it]) {
         c++;
         bridgeArtGo(*it,i);
      }
      art[i] = (c > 1);
   }
}

vi adj[MAXN];
int ojciec[MAXN], glebokosc[MAXN], renumber[MAXN];

void dfs (int v, int p, int d) {
   ojciec[v] = p;
   glebokosc[v] = d;
   FOREACH(x,adj[v]) if (*x != p) dfs(*x,v,d+1);
}

int main () {
   scanf("%d", &n);
   wez(m)
   while (m--) {
      wez2(a,b)
      adja[a].pb(b);
      adja[b].pb(a);
   }
   bridgeArt();
   UnionFind uf(n+1);
   set<pii> smosty(ALL(mosty));
   FORI(i,n) FOREACH(j,adja[i]) {
      if (!IN(mp(min(i,*j),max(i,*j)), smosty)) uf.unia(i, *j);
   }
   
   //FORI(i,n) { DBG(i)DBG(uf.find(i)) }
   
   int next = 1;
   FORI(i,n) if (i == uf.find(i)) renumber[i] = next++;
   
   //FORI(i,n) { DBG(i) DBG(uf.find(i)) }
   FOREACH(x,mosty) {
      int a = renumber[uf.find(x->fi)], b = renumber[uf.find(x->se)];
      adj[a].pb(b);
      adj[b].pb(a);
   }
   dfs(1,-1,0);
   LCA<100007,17> lca(next-1,1,ojciec);

   TESTS {
      wez2(v,w)
      v = renumber[uf.find(v)];
      w = renumber[uf.find(w)];
      int lc = lca(v,w);
      pisz(glebokosc[v] + glebokosc[w] - 2*glebokosc[lc]);
   }
}