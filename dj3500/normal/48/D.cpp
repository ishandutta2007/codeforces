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

int ile[100004];
int t[100004];

int main () {
   const int MAX = 100000;
   wez(n);
   FORI(i,n) scanf("%d",t+i);
   FORI(i,MAX) ile[i] = 0;
   FORI(i,n) ile[t[i]]++;
   FORI(i,MAX) {
      if (i==1) continue;
      if (ile[i] > ile[i-1]) {
//         DBG(i)        DBG(ile[i])         DBG(ile[i-1])
         printf("-1");
         return 0;
      }
   }
   printf("%d\n",ile[1]);
   FORI(i,MAX) ile[i] = 0;
   FORI(i,n) {
      ile[t[i]]++;
      printf("%d ",ile[t[i]]);
   }
   return 0;
}