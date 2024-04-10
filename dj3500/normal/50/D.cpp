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

double distsq[102], prob[102];
double dp[102][102];

int main () {
   wez(n);
   wez(k);
   wez(e);
   double wantedprob = 1-e/1000.0;
   wez(x0);
   wez(y0);
   FORI(i,n) {
      wez(x1);
      wez(y1);
      double odlx = x1-x0;
      double odly = y1-y0;
      distsq[i] = odlx*odlx + odly*odly;
   }
   // uwaga: jesli wszystkie sa w jednym punkcie, to wypisac 0
   
   const double eps = 0.00000000001;
   double a = 0, b = 4000;
   while (b-a > eps) {
      double r = (a+b)/2;
      
      FORI(i,n) {
         if (distsq[i] <= r*r) prob[i] = 1;
         else prob[i] = exp(1 - distsq[i]/(r*r));
      }
      //FORI(i,n) {DBG(i)DBG(distsq[i])DBG(prob[i])}
      
      // dp[i][j] = pnstwo ze z pierwszych i budynkow bedzie j zburzonych
      dp[0][0] = 1;
      for (int i = 1; i <= n; ++i) {
         dp[i][0] = dp[i-1][0] * (1 - prob[i]);
         //printf("dp[%d][%d] = %lf\n",i,0,dp[i][0]);
         for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i-1][j] * (1 - prob[i]) + dp[i-1][j-1] * prob[i];
            //printf("dp[%d][%d] = %lf\n",i,j,dp[i][j]);
         }
      }
      
//      DBG(dp[n][k])
      double prob = 0;
      for (int j = k; j <= n; ++j) prob += dp[n][j];
      if (prob >= wantedprob) b = r;
      else a = r;
   }
   printf("%.11lf\n",a);
}