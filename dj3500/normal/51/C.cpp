#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
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


int main () {
   wez(n);
   vector<double> v;
   FOR(i,n) {wez(asdas); v.pb(asdas); }
   sort(v.begin(),v.end());
   vector<double> w;
   FOR(i,n) w.pb(v[n-1-i]);
   
   double pos;
   double mind = 0, maxd = max(1.0,v[n-1]-v[0]);
   while (maxd - mind > 0.00000001) {
      double d = (mind+maxd)/2;
      vector<double>::iterator ub1 = upper_bound(v.begin(), v.end(), v[0] + 2*d),
      ub2 = upper_bound(w.begin(), w.end(), v[n-1] - 2*d, greater<double>());
      bool ok;
      bool easy = false;
      double minv,maxv;
      if (ub1 == v.end() || ub2 == w.end()) {
         ok = true;
         easy = true;
      } else {
         minv = *(ub1);
         maxv = *(ub2);
         ok = (maxv - minv <= 2*d);
      }
      if (ok) {
         maxd = d;
         if (easy) pos = 0;
         else pos = (minv+maxv)/2;
      } else {
         mind = d;
      }
   }
   
   printf("%.6lf\n%.6lf %.6lf %.6lf\n",mind,v[0] + mind , pos, v[n-1] - mind);
}