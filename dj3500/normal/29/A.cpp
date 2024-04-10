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

int x[101], d[101];

int main () {
   wez(n);
   FORI(i,n) {
      scanf("%d %d", x+i,d+i);
   }
   FORI(i,n) {
      FORI(j,n) {
         if (i != j) {
            if ((x[i] == x[j] + d[j]) && (x[j] == x[i] + d[i])) {
               printf("YES");
               return 0;
            }
         }
      }
   }
   printf("NO");
   return 0;
}