#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

int Kx[1005], Ky[1005];
int r[1005],Cx[1005],Cy[1005];
int g[1005][1005], dist[1005][1005];
int gdzie[1005];

vector<int> toposort (int n) {
   vector<int> ins(n+1,0), kolejnosc;
   FORI(i,n) {
      FORI(gg,n) if (g[i][gg])
         ++ins[gg];
      
   }
   deque<int> kol;
   FORI(i,n) {
      if (ins[i] == 0) {
         kol.pb(i);
      }
   }
   int przetworzonych = 0;
   while (!kol.empty()) {
      int i = kol.front();
      kol.pop_front();
      FORI(gg,n) {
         if (g[i][gg]) {
            --ins[gg];
            if (ins[gg] == 0) kol.pb(gg);
         }
      }
      kolejnosc.pb(i);
   }
   return kolejnosc;
   // jesli przetworzonych != n, to byly cykle i fail
}


int main () {
   wez(n);wez(m);wez(k);
   FORI(i,n) {
      scanf("%d %d", Kx+i, Ky+i);
   }
   FORI(i,m) {
      scanf("%d %d %d",r+i,Cx+i,Cy+i);
   }
   
   FORI(i,m) FORI(j,m) {
      g[i][j] = 0;
      if (r[i] < r[j]) {
         ll xd = Cx[j] - Cx[i];
         ll yd = Cy[j] - Cy[i];
         ll rr = r[j];
         if (xd*xd + yd*yd <= rr*rr) {
            g[i][j] = 1;
            //printf("%d jest w %d\n",i,j);
         }
      }
   }
   
   FORI(i,m) {
      g[i][m+1] = 1; g[m+1][i] = 0;
   }
   
   vector<int> kolejnosc = toposort(m+1);
   
//   FORI(i,kolejnosc.size()-1) printf("%d ",kolejnosc[i]);

   FORI(i,m+1) FORI(j,m+1) dist[i][j] = INF;

   FOR(i,kolejnosc.size()) {
      int d = 1;
      dist[kolejnosc[i]][kolejnosc[i]] = 0;
      for (int j = i+1; j < kolejnosc.size(); ++j) {
         if (g[kolejnosc[i]][kolejnosc[j]]) dist[kolejnosc[i]][kolejnosc[j]] = dist[kolejnosc[j]][kolejnosc[i]] = d++;
      }
   }
   
   FORI(a,n) {
      int rad = INF+500;
      gdzie[a] = m+1;
      FORI(i,m) {
         ll xd = Kx[a] - Cx[i];
         ll yd = Ky[a] - Cy[i];
         ll rr = r[i];
         if ((rad > r[i]) && (xd*xd + yd*yd <= rr*rr)) {
            rad = r[i];
            gdzie[a] = i;
         }
      }
   }
   
   //FORI(i,m+1) FORI(j,m+1) printf("g[%d][%d] = %d\n", i,j,g[i][j]);
   
   while (k--) {
      wez(a);wez(b);

      int gdziea = gdzie[a], gdzieb=gdzie[b];
      
      int minkoszt = INF;
      FORI(th,m+1) {
         if ((g[gdziea][th] || gdziea==th) && (g[gdzieb][th] || gdzieb==th)) {
            minkoszt = min(minkoszt, dist[gdziea][th] + dist[th][gdzieb]);
         }
      }
      printf("%d\n", minkoszt);
   }
   return 0;
}