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

int main () {
   wez3(n,m,k)
   map<int,vector<pii> > segments[2];
   FOR(i,k) {
      wez2(xbi,ybi)
      wez2(xei,yei)
      if (xbi > xei) swap(xbi, xei);
      if (ybi > yei) swap(ybi, yei);
      if (xbi == xei) {
         segments[0][xbi].pb(mp(ybi,1));
         segments[0][xbi].pb(mp(yei,-1));
      } else {
         segments[1][ybi].pb(mp(xbi,1));
         segments[1][ybi].pb(mp(xei,-1));
      }
   }
   int dim[2] = {n,m}, xo = 0;
   vector<pair<pii,int> > cands;
   FOR(u,2) {
      FOREACH(it,segments[u]) {
         int x = it->fi;
         vector<pii> &v = it->se;
         sort(ALL(v));
         v.pb(mp(dim[1-u],1));
         int lev = 0, prev = 0, len = 0;
         FOREACH(jt,v) {
            if (lev == 0) len += jt->fi - prev;
            prev = jt->fi;
            lev += jt->se;
         }
         cands.pb(mp(mp(u,x), len));
         xo ^= len;
      }
      
      int rest = dim[u]-1 - SZ(segments[u]);
      if (1 & rest) {
         xo ^= dim[1-u];
      }
      if (rest > 0) {
         cands.pb(mp(mp(u,-1), dim[1-u]));
      }
   }
   if (xo == 0) {
      printf("SECOND");
   } else {
      printf("FIRST\n");
      
      pii bestind; int reduction;
      FOREACH(it,cands) {
         int ai = it->se;
         if ((ai ^ xo) < ai) {
            bestind = it->fi;
            reduction = ai - (ai ^ xo);
            break;
         }
      }
      
      int u = bestind.fi;
      //DBG(bestind.se)
      if (bestind.se == -1) {
         int cur = 1;
         bool broken = 0;
         FOREACH(it,segments[u]) {
            if (it->fi != cur) {
               bestind.se = cur;
               broken = 1;
               break;
            } else {
               ++cur;
            }
         }
         if (!broken) bestind.se = cur;
      }
      int x = bestind.se;
      //DBG(x)
      
      // go
      vector<pii> &v = segments[u][x];
      v.pb(mp(dim[1-u],1)); // can't hurt
      int lev = 0, prev = 0, len = 0;
      FOREACH(jt,v) {
         if (lev == 0) {
            len += jt->fi - prev;
            if (len >= reduction) {
               int pos = jt->fi - (len - reduction);
               if (u == 0) {
                  printf("%d %d %d %d", x, 0, x, pos);
               } else {
                  printf("%d %d %d %d", 0, x, pos, x);
               }
               return 0;
            }
         }
         prev = jt->fi;
         lev += jt->se;
      }
      
   
   }
}