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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
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


vector<vi> podziel_na_skladowe (int n, vi *adj) {
	vector<bool> vis(n+1,0);
	vector<vi> wyn;
	FORI(i,n) {
		if (vis[i]) continue;
		vi skladowa;
		deque<int> q;
		q.pb(i);
		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			if (vis[v]) continue;
			vis[v]=1;
			skladowa.pb(v);
			FOR(j,SZ(adj[v])) q.pb(adj[v][j]);
		}
		wyn.pb(skladowa);
	}
	return wyn;
}

#define N 307
int v, n, a[N], b[N];
vi adj[N];

vector<pair<pii,int> > res;
void lej (int from, int to, int ile) {
   if (ile > 0) {
      res.pb(mp(mp(from,to), ile));
      a[from] -= ile;
      a[to] += ile;
   }
}

void zbieraj (int u, int p) {
   //printf("zbieraj(%d,%d)\n", u, p);
   FOREACH(e,adj[u]) if (*e != p) {
      if (a[u] == v) return;
      zbieraj(*e, u);
      if (a[*e] > 0) lej(*e, u, min(v - a[u], a[*e]));
   }
}

void wypr (int u, int p) {
   //printf("wypr(%d,%d)\n", u, p);
   FOREACH(e,adj[u]) if (*e != p) {
      if (a[u] == 0) break;
      wypr(*e, u);
      if (a[*e] < v) lej(u, *e, min(a[u], v - a[*e]));
   }
}

int main () {
   int m;
   scanf("%d %d %d", &n, &v, &m);
   UnionFind uf(n+5);
   FORI(i,n) {
      scanf("%d", a+i);
   }
   FORI(i,n) {
      scanf("%d", b+i);
   }
   while (m--) {
      wez2(ai,bi);
      if (uf.unia(ai,bi)) {
         adj[ai].pb(bi);
         adj[bi].pb(ai);
      }
   }
   
   vector<vi> skladowe = podziel_na_skladowe(n, adj);
   //DBG(skladowe)
   FOREACH(skl,skladowe) {
      ll suma = 0;
      FOR(u,SZ(*skl)) {
         int i = (*skl)[u];
         suma += a[i];
         suma -= b[i];
      }
      if (suma != 0) {
         printf("NO");
         return 0;
      }
   }
   
   while (1) {
      // znajdz lisc
      int i = -1;
      FORI(x,n) if (SZ(adj[x]) == 1) {
         i = x; break;
      }
      if (i == -1) {
break;
}
      // i: lisc
      int r = adj[i][0];
      //DBG(mp(i,r))
      if (a[i] < b[i]) {
         zbieraj(r, i);
         lej(r, i, b[i] - a[i]);
      } else if (a[i] > b[i]) {
         wypr(r, i);
         lej(i, r, a[i] - b[i]);
      }
      
      // wywal i z grafu
      adj[i].clear();
      FORI(x,n) {
         vi nowy;
         FOREACH(it,adj[x]) if (*it != i) nowy.pb(*it);
         adj[x] = nowy;
      }
   }
   
   pisz(SZ(res));
   FOREACH(x,res) {
      printf("%d %d %d\n", x->fi.fi, x->fi.se, x->se);
   }
}