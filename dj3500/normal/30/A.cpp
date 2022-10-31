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

ll power (ll a, int b) {
   if (b==0) return 1LL;
   else return a*power(a,b-1);
}

int main () {
   wez(A);wez(B);wez(n);
   for (int w = 0; w <= 1000; ++w) {
      if ((power((ll)w,n) > 1000) || (power((ll)w,n) < -1000)) break;
      if ((ll)A * power((ll)w,n) == (ll)B) {
         printf("%d",w);
         return 0;
      }
   }
   for (int w = 0; w >= -1000; --w) {
      if ((power((ll)w,n) > 1000) || (power((ll)w,n) < -1000)) break;
      if ((ll)A * power((ll)w,n) == (ll)B) {
         printf("%d",w);
         return 0;
      }
   }

   printf("No solution");
   return 0;
}