#define SYF freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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

#define MAXV 1000100
int n, m;
vi adj[MAXV];
int para[MAXV], dist[MAXV];

bool bfs() {
   deque<int> q;
   FORI(v,n) {
      if (!para[v]) {
         dist[v]=0;
         q.pb(v);
      } else dist[v] = INF;
   }
   dist[0] = INF;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOR(i,SZ(adj[v])) {
         int u = adj[v][i];
         if (dist[para[u]] == INF) {
            dist[para[u]] = dist[v]+1;
            q.pb(para[u]);
         }
      }
   }
   return dist[0] != INF;
}

bool dfs (int v) {
   if (!v) return 1;
   FOR(i,SZ(adj[v])) {
      int u = adj[v][i];
      if (dist[para[u]] == dist[v]+1) {
         if (dfs(para[u])) {
            para[u]=v;
            para[v]=u;
            return 1;
         }
      }
   }
   dist[v]=INF;
   return 0;
}

int matching () {
   FOR(i,n+m+1) para[i]=0;
   int w = 0;
   while (bfs()) FORI(v,n) if (!para[v]) if (dfs(v)) ++w;
   return w;
}

int ktory4[30][30][30][30], ktory3[30][30][30], ktory2[30][30], ktory1[30];
string pocz[240], wynik[240];
char s[14];
bool obrobiony[MAXV];

int main () {
   SYF
   FOR(i,MAXV) obrobiony[i] = 0;
   scanf("%d",&n);
   int teraz = n; // ++teraz
   FOR(a,30)FOR(b,30)FOR(c,30)FOR(d,30) ktory4[a][b][c][d] = 0;
   FOR(a,30)FOR(b,30)FOR(c,30) ktory3[a][b][c] = 0;
   FOR(a,30)FOR(b,30) ktory2[a][b] = 0;
   FOR(a,30) ktory1[a] = 0;
   FORI(i,n) {
      scanf("%s",s);
      pocz[i] = s;
   }

   // 1
   FORI(i,n) {
      FOR(j,SZ(pocz[i])) {
         char c = pocz[i][j] - 'a';
         if (ktory1[c] == 0) ktory1[c] = ++teraz;
         adj[i].pb(ktory1[c]);
      }
   }

   // 2
   FORI(i,n) {
      FOR(j1,SZ(pocz[i])) REP(j2,j1+1,SZ(pocz[i])-1) {
         char c1 = pocz[i][j1] - 'a', c2 = pocz[i][j2] - 'a';
         if (ktory2[c1][c2] == 0) ktory2[c1][c2] = ++teraz;
         adj[i].pb(ktory2[c1][c2]);
      }
   }

   // 3
   FORI(i,n) {
      FOR(j1,SZ(pocz[i])) REP(j2,j1+1,SZ(pocz[i])-1) REP(j3,j2+1,SZ(pocz[i])-1) {
         char c1 = pocz[i][j1] - 'a', c2 = pocz[i][j2] - 'a', c3 = pocz[i][j3] - 'a';
         if (ktory3[c1][c2][c3] == 0) ktory3[c1][c2][c3] = ++teraz;
         adj[i].pb(ktory3[c1][c2][c3]);
      }
   }

   // 4
   FORI(i,n) {
      FOR(j1,SZ(pocz[i])) REP(j2,j1+1,SZ(pocz[i])-1) REP(j3,j2+1,SZ(pocz[i])-1) REP(j4,j3+1,SZ(pocz[i])-1) {
         char c1 = pocz[i][j1] - 'a', c2 = pocz[i][j2] - 'a', c3 = pocz[i][j3] - 'a', c4 = pocz[i][j4] - 'a';
         if (ktory4[c1][c2][c3][c4] == 0) ktory4[c1][c2][c3][c4] = ++teraz;
         adj[i].pb(ktory4[c1][c2][c3][c4]);
      }
   }

   m = teraz-n;
   int match = matching();
   if (match < n) {
      printf("-1");
      return 0;
   }

   // 1
   FORI(i,n) {
      FOR(j,SZ(pocz[i])) {
         char c = pocz[i][j] - 'a';
         int kt = ktory1[c];
         if (para[kt]) {
            if (obrobiony[kt]) continue;
            obrobiony[kt] = 1;
            wynik[para[ktory1[c]]] += c  + 'a';
         }
      }
   }

   // 2
   FORI(i,n) {
      FOR(j1,SZ(pocz[i])) REP(j2,j1+1,SZ(pocz[i])-1) {
         char c1 = pocz[i][j1] - 'a', c2 = pocz[i][j2] - 'a';
         int kt = ktory2[c1][c2];
         if (para[kt]) {
            if (obrobiony[kt]) continue;
            obrobiony[kt] = 1;
            wynik[para[kt]] += c1 + 'a';
            wynik[para[kt]] += c2 + 'a';
         }
      }
   }

   // 3
   FORI(i,n) {
      FOR(j1,SZ(pocz[i])) REP(j2,j1+1,SZ(pocz[i])-1) REP(j3,j2+1,SZ(pocz[i])-1) {
         char c1 = pocz[i][j1] - 'a', c2 = pocz[i][j2] - 'a', c3 = pocz[i][j3] - 'a';
         int kt = ktory3[c1][c2][c3];
         if (para[kt]) {
            if (obrobiony[kt]) continue;
            obrobiony[kt] = 1;
            wynik[para[kt]] += c1 + 'a';
            wynik[para[kt]] += c2 + 'a';
            wynik[para[kt]] += c3 + 'a';
         }
      }
   }

   // 4
   FORI(i,n) {
      FOR(j1,SZ(pocz[i])) REP(j2,j1+1,SZ(pocz[i])-1) REP(j3,j2+1,SZ(pocz[i])-1) REP(j4,j3+1,SZ(pocz[i])-1) {
         char c1 = pocz[i][j1] - 'a', c2 = pocz[i][j2] - 'a', c3 = pocz[i][j3] - 'a', c4 = pocz[i][j4] - 'a';
         int kt = ktory4[c1][c2][c3][c4];
         if (para[kt]) {
            if (obrobiony[kt]) continue;
            obrobiony[kt] = 1;
            wynik[para[kt]] += c1 + 'a';
            wynik[para[kt]] += c2 + 'a';
            wynik[para[kt]] += c3 + 'a';
            wynik[para[kt]] += c4 + 'a';
         }
      }
   }

   FORI(i,n) printf("%s\n",wynik[i].c_str());

}