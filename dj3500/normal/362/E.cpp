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

namespace MCF {
   #define MAXN 100010
   #define MAXM 100010
   #define wint ll
   #define cint ll
   const wint wEPS = 0;
   const wint wINF = 1001001001001001001LL;
   const cint cEPS = 0;
   const cint cINF = wINF;
   int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
   wint capa[MAXM], tof;
   cint cost[MAXM], toc, d[MAXN], pot[MAXN];
   int vis[MAXN], pree[MAXN];
   void init(int _n) {
      n = _n+2; // na wszelki wypadek
      m = 0;
      memset(ptr, ~0, n << 2);
   }
   void ae(int u, int v, wint w, cint c) {
      next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
      next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
   }
   bool spRep(int src, int ink, wint flo = wINF) { // wynik to (tof,toc)
      wint f;
      cint c, cc;
      int i, u, v;
      memset(pot, 0, n * sizeof(cint));
   //*
      for (bool cont = 1; cont; ) {
         cont = 0;
         FOR(u,n) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
            if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
               pot[zu[i]] = pot[u] + cost[i]; cont = 1;
            }
         }
      }
   //*/
      for (toc = 0, tof = 0; tof + wEPS < flo; ) {
         typedef pair<cint,int> node;
         priority_queue< node,vector<node>,greater<node> > q;
         FOR(u,n) { d[u] = cINF; vis[u] = 0; }
         for (q.push(mp(d[src] = 0, src)); !q.empty(); ) {
            c = q.top().first; u = q.top().second; q.pop();
            if (vis[u]++) continue;
            for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
               cc = c + cost[i] + pot[u] - pot[v = zu[i]];
               if (d[v] > cc) { q.push(mp(d[v] = cc, v)); pree[v] = i; }
            }
         }
         if (!vis[ink]) return 0;
         f = flo - tof;
         for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; REMIN(f, capa[i]); }
         for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
         tof += f;
         toc += f * (d[ink] - pot[src] + pot[ink]);
         FOR(u,n) pot[u] += d[u];
      }
      return 1;
   }
}

int c[64][64];

int main () {
   wez2(n,k);
   FORI(i,n) FORI(j,n) scanf("%d", &c[i][j]);
   ll best = 0, from = 1, to = 200 * 1000000;
   while (from <= to) {
      ll mid = (from + to) / 2;
      MCF::init(n);
      FORI(i,n) FORI(j,n) if (c[i][j]) {
         MCF::ae(i,j,c[i][j],0);
         MCF::ae(i,j,MCF::wINF,1);
      }
      if (MCF::spRep(1,n,mid) && MCF::toc <= k) {
         best = mid;
         from = mid + 1;
      } else {
         to = mid - 1;
      }
   }
   printf("%lld", best);
}