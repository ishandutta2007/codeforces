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
      int fa = find(tab[a]);
      return tab[a] = fa;
   }

   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
      int fa = find(a), fb = find(b);

      if (fa==fb) return 0;
      if (ile[fa] <= ile[fb]) {
         ile[fb] += ile[fa];
         tab[fa] = fb;
      } else {
         ile[fa] += ile[fb];
         tab[fb] = fa;
      }
      return 1;
   }
};

char s[1024][1024];
vector<pii> neighs[1000006];
int temp[1024][1024]; // 0 - out of set, 1 - unvisited, 2 - visited
int n,m;

#define ok(a,b) (a >= 0 && a < n && b >= 0 && b < m)

void dfs (int x, int y) {
   if (temp[x][y] != 1) return;
   temp[x][y] = 2;
   int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};
   FOR(u,4) {
      int x1 = x+dx[u], y1 = y+dy[u];
      if (ok(x1,y1)) dfs(x1,y1);
   }
}

bool isConnectedAndEveryPointHasTwoNeighbours (const vector<pii> &st) {
   FOR(i,SZ(st)) temp[st[i].fi][st[i].se] = 1;
   dfs(st[0].fi,st[0].se);
   bool wrong = 0;
   FOR(i,SZ(st)) {
      if (temp[st[i].fi][st[i].se] != 2) wrong = 1;
      int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0}, cnt = 0;
      FOR(u,4) {
         int x = st[i].fi + dx[u], y = st[i].se + dy[u];
         if (ok(x,y) && temp[x][y] == 2) ++cnt;
      }
      if (cnt != 2) wrong = 1;
   }
   FOR(i,SZ(st)) temp[st[i].fi][st[i].se] = 0;
   return !wrong;
}

inline int c (int x, int y) {
   return x*m + y;
}

int main () {
   FOR(i,1024) FOR(j,1024) temp[i][j] = 0;
   
   scanf("%d %d",&n,&m);
   FOR(i,n) scanf("%s",s[i]);
   int res = 0;
   FOR(i,n-1) FOR(j,m-1) {
      if (s[i][j] == '1' && s[i+1][j] == '1' && s[i][j+1] == '1' && s[i+1][j+1] == '1') res = 4;
   }
   
   UnionFind uf0(n*m); // by corners also
   FOR(i,n) FOR(j,m) if (s[i][j] == '0') {
      if (i < n-1) if (s[i+1][j] == '0') uf0.unia(c(i,j),c(i+1,j));
      if (j < m-1) if (s[i][j+1] == '0') uf0.unia(c(i,j),c(i,j+1));
      if (i < n-1 && j < m-1) if (s[i+1][j+1] == '0') uf0.unia(c(i,j),c(i+1,j+1));
      if (i > 0 && j < m-1) if (s[i-1][j+1] == '0') uf0.unia(c(i,j),c(i-1,j+1));
   }
   //DBG(n)
   
   vector<bool> hasborder(1000006,0);
   
   int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1},
       dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
   FOR(i,n) FOR(j,m) if (s[i][j] == '0') {
      int k = uf0.find(c(i,j));
      if (hasborder[k]) continue; // niepotrzebne
      FOR(u,8) {
         const int x = i + dx[u], y = j + dy[u];
         if (!ok(x,y)) {
            // graniczymy z granica planszy; to zle
            hasborder[k] = 1;
            break;
         }
         if (s[x][y] == '1') neighs[k].pb(mp(x,y));
      }
   }
   //DBG(n)
   
   FOR(i,n) FOR(j,m) if (s[i][j] == '0') if (uf0.find(c(i,j)) == c(i,j)) {
      int k = c(i,j);
      if (hasborder[k]) continue;
      //DBG(k)
      //DBG(neighs[k])
      sort(ALL(neighs[k]));
      vector<pii> uniq;
      FOR(f,SZ(neighs[k])) {
         if (uniq.empty() || uniq.back() != neighs[k][f]) {
            uniq.pb(neighs[k][f]);
         }
      }
      
      if (isConnectedAndEveryPointHasTwoNeighbours(uniq)) res = max(res, SZ(uniq));
   }
   
   pisz(res);
}