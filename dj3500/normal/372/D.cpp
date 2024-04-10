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

#define N 100007
#define LOGN 17
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

vi adj[N];
int tim[N], t, depth[N];

void dfs (int v, int p, int d) {
   ojc[v] = p;
   tim[v] = ++t;
   depth[v] = d;
   FOREACH(x,adj[v]) if (p != *x) {
      dfs(*x,v,d+1);
   }
}

int getDist (int i, int j) {
   return depth[i] + depth[j] - 2 * depth[lca(i,j)];
}

struct comp { bool operator () (int i, int j) { return tim[i] < tim[j]; } };
set<int,comp> s;
int dist = 0;

void insert (int i) {
   //printf("insert %d\n", i);
   set<int,comp>::iterator p = s.insert(i).fi, nxt, prv;
   if (SZ(s) == 1) {
      return;
   }
   nxt = p;
   ++nxt;
   if (nxt == s.end()) nxt = s.begin();
   prv = p;
   if (prv == s.begin()) {
      prv = s.end();
   }
   --prv;
   dist -= getDist(*prv, *nxt);
   dist += getDist(*prv, i);
   dist += getDist(i, *nxt);
}
void erase (int i) {
   //printf("erase %d\n", i);
   if (SZ(s) == 1) {
      s.clear();
      return;
   }
   set<int,comp>::iterator p = s.find(i), nxt, prv;
   nxt = p;
   ++nxt;
   if (nxt == s.end()) nxt = s.begin();
   prv = p;
   if (prv == s.begin()) {
      prv = s.end();
   }
   --prv;
   dist += getDist(*prv, *nxt);
   dist -= getDist(*prv, i);
   dist -= getDist(i, *nxt);
   s.erase(p);
}

int main () {
   int k;
   scanf("%d %d", &n, &k);
   FOR(i,n-1) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   t = 0;
   dfs(1,-1,0);
   init(1);
   int res = 0;
   //s.insert(1);
   
   int ri = 0;
   FORI(le,n) {
      while (ri < n) {
         ++ri;
         insert(ri);
         if (dist <= 2*k-2) {
            REMAX(res, ri-le+1);
         } else {
            erase(ri);
            --ri;
            break;
         }
      }
      erase(le);
   }
   
   pisz(res);
}