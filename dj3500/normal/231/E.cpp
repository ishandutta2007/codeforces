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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);


#define MAXN 100006

/*struct edge {
   int v, // dokad prowadzi krawedz
   dcc; // numer spojnej skladowej
   bool bridge; // czy krawedz jest mostem
   int rev; // pozycja krawedzi z v do u w wektorze adje[v], dzieki ktorej
            // mozna znajdowac krawedzie o przeciwnym zwrocie w czasie stalym
   edge(int _v, int r) : v(_v), rev(r) {}
};
vector<edge> adje[MAXN];
void dodaj_krawedz(int a, int b) {
   adje[a].pb(edge(b, SZ(adje[b]) + (a==b)));
   adje[b].pb(edge(a, SZ(adje[a])-1));
}


// implementacja:
int low[MAXN], wej[MAXN], skl, czas;
vector<vector<edge>::iterator> qu;
#define DccMark(bri) e->dcc = adje[e->v][e->rev].dcc = skl, e->bridge = adje[e->v][e->rev].bridge = bri
void dccSearch(int v, int u) {
   wej[v] = low[v] = czas++;
   FOREACH(it,adje[v]) {
      int w = it->v;
      if (wej[w] == -1) {
         qu.pb(it);
         dccSearch(w,v);
         if (low[w] >= wej[v]) {
            // znaleziono dwuspojna skladowa
            int cnt = 0;
            vector<edge>::iterator e;
            do {
               e = qu.back();
               DccMark(0);
               qu.pop_back();
               cnt++;
            } while (e != it);
            if (cnt == 1) DccMark(1); // mamy most
            skl++;
         } else low[v] = min(low[v], low[w]);
      } else if (wej[w] < wej[v] && w != u) {
         qu.pb(it);
         low[v] = min(low[v], wej[w]);
      }
   }
}
void dcc() {
   skl = czas = 0;
   qu.clear();
   FORI(i,n) wej[i] = -1;
   FORI(i,n) if (wej[i] == -1) dccSearch(i,-1);
}
*/


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

UnionFind *uf;
int n;
vi adj[MAXN];


int state[MAXN]; // 0 - unvisited, 1 - gray, 2 - black
int go (int v, int p) {
   if (state[v] == 2) return -1; // no cycle
   if (state[v] == 0) {
      state[v] = 1;
      int ret = -1;
      FOREACH(x,adj[v]) if (*x != p) {
         int res = go(*x,v);
         if (res != -1) {
            ret = res;
            uf->unia(*x,v);
         }
      }
      state[v] = 2;
      if (ret == v) return -1; // back to normal
      else return ret;
   } else {
      // 1 - gray, cycle
      uf->unia(v,p);
      return v;
   }
}


int zilu[MAXN];
int ojciec[MAXN];
int potencjal[MAXN];
vi adj2[MAXN];
bool vis[MAXN];
void dfs (int v, int p, int pot) {
   if (vis[v]++) return;
   ojciec[v] = p;
   potencjal[v] = pot += (zilu[v] > 1);
   FOREACH(x,adj2[v]) if (*x != p) dfs(*x,v,pot);
}
ll potega[MAXN];
int real[MAXN], t[MAXN];

int main () {
   scanf("%d", &n);
   potega[0] = 1;
   FORI(i,n) potega[i] = (potega[i-1] * 2) % 1000000007;
   TESTS {
      wez2(a,b)
      //dodaj_krawedz(a,b);
      adj[a].pb(b);
      adj[b].pb(a);
   }
   uf = new UnionFind(n+1);

   go(1,-1);
   /*dcc();
   vi occurs(100005,0);
   FORI(i,n) FOREACH(ed,adje[i]) {
      occurs[ed->dcc]++;
   }
   FORI(i,n) FOREACH(ed,adje[i]) if (occurs[ed->dcc] > 2) {
      uf->unia(ed->v, i);
   }*/


   int kol = 1;
   FORI(i,n) if (uf->find(i) == i) {
      real[i] = kol++;
   }
   int n2 = kol - 1;
   FORI(i,n) t[i] = real[uf->find(i)];
   FOR(i,n) FOREACH(x,adj[i]) {
      adj2[t[i]].pb(t[*x]);
   }

   FORI(i,n) zilu[t[i]]++;
   const int root = 1;
   dfs(root,-1,0);
   LCA<100007,17> lca(n2,root,ojciec);
   wez(q)
   while (q--) {
      wez2(a,b)
      int lc = lca(t[a],t[b]);
      int res = potencjal[t[a]] + potencjal[t[b]] - 2*potencjal[lc] + (zilu[lc] > 1);
      pisz(potega[res]);
   }
}