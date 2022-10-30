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

// przyklad uzycia:
// LCA<100003,17> lca(n,root,ojciec);
// int k = lca(u,v);

// pod Windowsem uwaga na limit na stos!

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

template <typename T, typename Aug>
struct AugTreap {
   struct Node {
      T v; // wartosc
      int pr; // priorytet
      Node *le, *ri;
      Aug al, ag; // aug dla samego wierzcholka i dla calego poddrzewa
   };

   Node *root;
   AugTreap() : root(0) {}

   inline static void recalc(Node* &n) { // oblicza nowe ag dla n
      Aug left = n->le ? n->le->ag + n->al : n->al;
      n->ag = n->ri ? left + n->ri->ag : left;
   }

   inline void rotle(Node* &n) { // wyciagnij lewe dziecko n do gory
      Node *syn = n->le;
      n->le = syn->ri;
      syn->ri = n;
      n = syn;

      recalc(n->ri);
      recalc(n);
   }

   inline void rotri(Node* &n) { // wyciagnij prawe dziecko n do gory
      Node *syn = n->ri;
      n->ri = syn->le;
      syn->le = n;
      n = syn;

      recalc(n->le);
      recalc(n);
   }

   void insert_aux(Node* &n, const T &x, const Aug &aug) {
      if (!n) {
         n = new Node;
         n->v = x;
         n->pr = rand();
         n->le = n->ri = 0;
         n->al = n->ag = aug;
      } else if (x < n->v) {
         insert_aux(n->le, x, aug);
         if (n->pr > n->le->pr) rotle(n);
         else recalc(n);
      } else if (x > n->v) {
         insert_aux(n->ri, x, aug);
         if (n->pr > n->ri->pr) rotri(n);
         else recalc(n);
      } else {
         // x juz jest w drzewie - robimy update
         n->al = n->al + aug;
         // n->al = aug; // OVERWRITE
         recalc(n);
      }
   }

   void insert (const T &x, const Aug &aug) {
      insert_aux(root, x, aug);
   }
   
   Aug sumgeq_aux (const T &x, Node *n) {
      if (!n) return Aug();
      if (x > n->v) return sumgeq_aux(x, n->ri);
      if (x < n->v) {
         Aug left = sumgeq_aux(x, n->le) + n->al;
         return n->ri ? left + n->ri->ag : left;
      }
      // x == n->v
      return n->ri ? n->al + n->ri->ag : n->al;
   }

   // suma Augw po wszystkich kluczach >= x
   Aug sumgeq (const T &x) {
      return sumgeq_aux(x,root);
   }

// ****************************************
// OPCJONALNE: SUMY W PGRUPIE
// (jeli Aug to grupa, to zamiast sumbetween(L,R) mona robi sumgeq(L) - sumgeq(R+1))
// ****************************************

   Aug sumleq_aux (const T &x, Node *n) {
      if (!n) return Aug();
      if (x < n->v) return sumleq_aux(x, n->le);
      if (x > n->v) {
         Aug right = n->al + sumleq_aux(x, n->ri);
         return n->le ? n->le->ag + right : right;
      }
      // x == n->v
      return n->le ? n->le->ag + n->al : n->al;
   }
   
   // suma Augw po wszystkich kluczach <= x
   Aug sumleq (const T &x) {
      return sumleq_aux(x,root);
   }
   
   Aug sumbetween_aux (const T &x, const T &y, Node *n) {
      if (!n) return Aug();
      if (y < n->v) return sumbetween_aux(x,y,n->le);
      if (x > n->v) return sumbetween_aux(x,y,n->ri);
      // x <= n->v <= y
      return sumgeq_aux(x,n->le) + n->al + sumleq_aux(y,n->ri);
   }
   
   // suma Augw po wszystkich kluczach z [x,y]
   Aug sumbetween (const T &x, const T &y) {
      return sumbetween_aux(x,y,root);
   }
};

#define N 100007
int ojciec[N], inorder[N], largestdescendant[N], ans[N], depth[N];//, ilutypow[N];
vector<pii> adj[N];
vi //dolca[N],
 arrowsToThisDepth[N];
int t = 0;

void dfs (int v, int p, int d) {
   depth[v] = d;
   inorder[v] = ++t;
   largestdescendant[v] = t;
   ojciec[v] = p;
   FOREACH(x,adj[v]) if (x->fi != p) {
      dfs(x->fi, v, d+1);
      largestdescendant[v] = largestdescendant[x->fi];
   }
}

/*void d2 (int v, int p) {
   ilutypow[v] = SZ(dolca[v]);
   FOREACH(x,adj[v]) if (x->fi != p) {
      d2(x->fi, v);
      ilutypow[v] += ilutypow[x->fi];
   }
}*/

struct Query {
   int from, to, lessThanWhat, edge, something;
   inline bool operator < (const Query &q) const {
      if (lessThanWhat != q.lessThanWhat) return lessThanWhat < q.lessThanWhat;
      return something < q.something;
   }
};
vector<Query> queries;
int somethingg = 0;

void go (int v, int p, int edge) {
   Query (q){inorder[v],largestdescendant[v],depth[v],edge,somethingg++};
   queries.pb(q);
   FOREACH(x,adj[v]) if (x->fi != p) {
      go(x->fi, v, x->se);
   }
}

int main () {
   wez(cities)
   FOR(i,cities-1) {
      wez2(a,b)
      adj[a].pb(mp(b,i));
      adj[b].pb(mp(a,i));
      ans[i] = 0;
   }
   wez(k)
   dfs(1,-1,0);
   LCA<100007,17> lca(cities,1,ojciec);
   while (k--) {
      wez2(a,b)
      int de = depth[lca(a,b)];
      //dolca[a].pb(de);
      arrowsToThisDepth[de].pb(inorder[a]);
      //dolca[b].pb(de);
      arrowsToThisDepth[de].pb(inorder[b]);
   }
   
   //d2(1,-1);
   go(1,-1,100003);
   sort(ALL(queries));
   int lastDepth = -1;
   AugTreap<pii,int> tr;
   FOREACH(q,queries) {
      REP(dep,lastDepth+1,q->lessThanWhat - 1) {
         FOREACH(it,arrowsToThisDepth[dep]) {
            tr.insert(mp(*it,somethingg++), 1);
         }
      }
      lastDepth = q->lessThanWhat - 1;
      
      ans[q->edge] += tr.sumbetween(mp(q->from,-1), mp(q->to, INF));
   }
   
   FOR(i,cities-1) printf("%d ", ans[i]);
}