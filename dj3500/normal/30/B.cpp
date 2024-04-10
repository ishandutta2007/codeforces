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
int dd,mm,yy;
inline void pisz(int n) {
   printf("%d\n",n);
}

bool sprawdz(int d, int m, int y) {
   if (m > 12) return false;
   if (d > 31) return false;
   if (m == 4 || m == 6 || m == 9 || m == 11) if (d == 31) return false;
   if (m == 2) if (d == 30) return false;
   if (y % 4 != 0) if (m == 2) if (d == 29) return false;
   if (y+18 > yy) return false;
   if (y+18 < yy) return true;
   if (m > mm) return false;
   if (m < mm) return true;
   if (d > dd) return false;
   return true;
}


int main () {
   int bd,bm,by;
   scanf("%d.%d.%d",&dd,&mm,&yy);
   scanf("%d.%d.%d",&bd,&bm,&by);
   if (sprawdz(bd,bm,by) || sprawdz(bd,by,bm) || sprawdz(bm,bd,by) || sprawdz(bm,by,bd) || sprawdz(by,bd,bm) || sprawdz(by,bm,bd)) {
      printf("YES");
   } else printf("NO");
   return 0;
   
}