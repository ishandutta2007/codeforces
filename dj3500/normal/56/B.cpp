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

int a[1002];

int main () {
   wez(n);
   FORI(i,n) {wez(x);a[i]=x;}
   
   int smallest = 0, largest = 0;
   FORI(i,n) if (a[i]!=i) { smallest = i; break; }
   for (int i = n; i >= 1; --i) if (a[i]!=i) { largest = i; break; }
   
   if (smallest == 0) {
      printf("0 0\n");
   } else {
      for (int i = smallest; i <= largest; ++i) {
         if (a[i] != largest + smallest - i) {
            printf("0 0\n");
            return 0;
         }
      }
      printf("%d %d\n",smallest,largest);
   }
}