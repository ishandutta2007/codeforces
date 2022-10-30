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
int scoredol[N], scoregora[N], dol[N], gora[N];

int main () {
   wez3(hl,hr,n)
   FOR(i,N) scoredol[i] = scoregora[i] = dol[i] = gora[i] = 0;
   FOR(i,n) {
      int sc,a,b; char c;
      scanf("%d %c %d %d", &sc, &c, &a, &b);
      if (c == 'F') {
         REP(k,a,b-1) {
            scoredol[k] = sc;
            dol[k] = i+1;
         }
      } else {
         REP(k,a,b-1) {
            scoregora[k] = sc;
            gora[k] = i+1;
         }
      }
   }
   int best = 0;
   // strzelam w dol
   REP(odbic,1,200000) {
      int pion;
      if (1 & odbic) pion = hl + hr + 100 * (odbic - 1);
      else pion = hl - hr + 100 * odbic;
      double x = 100000.0 * hl / pion;
      int score = 0;
      vi seen(105,0);
      seen[0] = 1;
      bool czyGora = 0, fail = 0;
      while (x < 100000) {
         int xx = floor(x + 1e-9);
         if (czyGora) {
            if (seen[gora[xx]]++) {
               fail = 1;
               break;
            }
            score += scoregora[xx];
         } else {
            if (seen[dol[xx]]++) {
               fail = 1;
               break;
            }
            score += scoredol[xx];
         }
         x += 100000.0 * 100 / pion;
         czyGora = !czyGora;
      }
      if (!fail) REMAX(best, score);
   }
   // strzelam w gore
   REP(odbic,1,200000) {
      int pion;
      if (1 & odbic) pion = 200 - hl - hr + 100 * (odbic - 1);
      else pion = hr - hl + 100 * odbic;
      double x = 100000.0 * (100 - hl) / pion;
      int score = 0;
      vi seen(105,0);
      seen[0] = 1;
      bool czyGora = 1, fail = 0;
      while (x < 100000) {
         int xx = floor(x + 1e-9);
         // jesli x calkowity, to xx-- ?
         //if (abs(x - xx) < 1e-7) xx--;
         if (czyGora) {
            if (seen[gora[xx]]++) {
               fail = 1;
               break;
            }
            score += scoregora[xx];
         } else {
            if (seen[dol[xx]]++) {
               fail = 1;
               break;
            }
            score += scoredol[xx];
         }
         //if (odbic == 7) { DBG(x)DBG(czyGora)DBG(czyGora ? gora[xx] : dol[xx])}
         x += 100000.0 * 100 / pion;
         czyGora = !czyGora;
      }
      if (!fail) {
         REMAX(best, score);
         //DBG(score);
         //DBG(odbic);
      }
      //cerr << "\n\n";
   }
   pisz(best);
}