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
#define INF (int)2e9
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

struct q { int x,y,t; double p; };
q t[1005];
bool operator < (const q &a, const q &b) {
   return a.t < b.t;
}
double wyn[1005];

int main () {
   wez(n);
   FOR(i,n) {
      scanf("%d %d %d %lf",&(t[i].x),&(t[i].y),&(t[i].t),&(t[i].p));
   }
   sort(t,t+n);
   double bigmaks = -1;
   FOR(i,n) {
      double maks = t[i].p;
//      DBG(t[i].p);
  //    printf("rozwazam i = %d\n",i);
      FOR(j,i) {
         //printf("rozwazam i = %d, j = %d\n",i,j);
         if ((t[i].t - t[j].t > 8000) ||
          ((t[i].x - t[j].x)*(t[i].x - t[j].x) + (t[i].y - t[j].y)*(t[i].y - t[j].y) <= (t[j].t - t[i].t)*(t[j].t - t[i].t))) {
            //printf("odleglosc ok");
            if (maks < t[i].p + wyn[j]) maks = t[i].p + wyn[j];
         }
      }
      wyn[i] = maks;
      if (bigmaks < maks) bigmaks = maks;
   }
   printf("%.9lf",bigmaks);
   return 0;
}