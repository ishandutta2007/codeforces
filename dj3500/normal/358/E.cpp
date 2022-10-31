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
#define DBG(vari) //cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 1024
vi adj[N*N];

vector<pii> e;
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


int a[N][N], b[N][N], n, m;
pii mini(INF,INF);
//const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
const int dx[2] = {1,0}, dy[2] = {0,1};

bool check (int k) {
   DBG(k)
   FORI(i,n) FORI(j,m) {
      adj[1020*i + j].clear();
      e.clear();
      b[i][j] = 0;
   }
   for (int i = mini.fi % k; i <= n; i += k) {
      for (int j = mini.se % k; j <= m; j += k) {
         if (a[i][j]) {
            FOR(d,2) {
               int x = i + dx[d], y = j + dy[d];
               if (a[x][y]) {
                  if (i + k*dx[d] < 1 || i + k*dx[d] > n || j+k*dy[d] < 1 || j+k*dy[d] > m) return 0;
                  REP(u,0,k) {
                     b[i+u*dx[d]][j+u*dy[d]] = 1;
                  }
                  add_edge(1020*i + j, 1020*(i + k*dx[d]) + j+k*dy[d]);
                  DBG(mp(mp(i,j), mp(i + k*dx[d],j+k*dy[d])))
               }
            }
         }
      }
   }
   FORI(i,n) FORI(j,m) if (a[i][j] != b[i][j]) {
      DBG("niezgodnosc")
      return 0;
   }
   if (euler_undirected(1020 * n + m + 1027).empty()) {
      DBG("bezcykle")
      return 0;
   }
   return 1;
}

int main () {
   scanf("%d %d", &n, &m);
   FORI(i,n) FORI(j,m) scanf("%d", &a[i][j]);
   //int cnt = 0;
   FORI(i,n) FORI(j,m) if (a[i][j]) {
      //++cnt;
      REMIN(mini,mp(i,j));
   }
   int g = 0;
   FORI(i,n) {
      int len = 0;
      FORI(j,m+1) {
         if (a[i][j]) ++len;
         else {
            if (len > 1) g = __gcd(g, len-1);
            len = 0;
         }
      }
   }
   FORI(j,m) {
      int len = 0;
      FORI(i,n+1) {
         if (a[i][j]) ++len;
         else {
            if (len > 1) g = __gcd(g, len-1);
            len = 0;
         }
      }
   }
   //DBG(g)
   bool some = 0;
   REP(k,2,g) if (g % k == 0) {
      if (check(k)) {
         printf("%d ", k);
         some = 1;
      }
   }
   if (!some) pisz(-1);
}