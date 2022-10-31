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

int stat[1003];

int main () {
   wez(n);
   stat[0] = 0;
   FORI(i,n) scanf("%d",stat+i);
   double lb = 10;
   double ub = 1e9;
   
   FORI(i,n) {
      double new_lb = 10.0 * stat[i] / i;
      double new_ub = 10.0 * (stat[i]+1) / i;
      if (lb < new_lb) lb = new_lb;
      if (ub > new_ub) ub = new_ub;
   }

//   printf("lb = %lf, ub = %lf\n",lb,ub);
   double fuel1 = lb * (n+1) - 10.0 * stat[n];
   double fuel2 = ub * (n+1) - 10.0 * stat[n]; // duzo benzyny
   
   int stop = stat[n];
   while (1) {
      ++stop;
      fuel1 -= 10;
      fuel2 -= 10;
      if ((fuel1 < 10) && (fuel2 <= 10)) {
         printf("unique\n%d", stop);
         break;
      } else if ((fuel1 < 10) || (fuel2 <= 10)) {
         printf("not unique");
         break;
      }
   }
   /*
   bool warn = (floor(fuel2/10) == fuel2/10);
   printf("fuel1 = %lf, fuel2 = %lf\n",fuel1,fuel2);
   int pot1 = floor(fuel1/10), pot2 = floor(fuel2/10);
   if (warn) --pot2;
   DBG(pot1) DBG(pot2)
   
   if (pot1 != pot2) {
      printf("not unique\n");
   } else {
      printf("unique\n%d\n",pot1 + stat[n]);
   }*/
//   printf("%lf %lf",lb,ub);
}