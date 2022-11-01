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

ll power (ll a, ll b) {
   if (b==0) return 1;
   else return a*power(a,b-1);
}


int tab[31700][31];
int n;

int opt (int a, int b) {
   if (tab[a][b] != -1) return tab[a][b];
   //DBG(a) DBG(b)
   ll aa = a;
   ll bb = b;
   ll pwr = power(a,b);
   if (pwr >= n) {
      tab[a][b] = 1;
      return 1;
   }
   //DBG(opt(a+1,b))
   //DBG(opt(a,b+1))
   if (opt(a+1,b) == 0 || opt(a,b+1) == 0) {
      tab[a][b] = 1;
      return 1;
   } else if (opt(a+1,b) == 1 && opt(a,b+1) == 1) {
      tab[a][b] = 0;
      return 0;
   } else {
      tab[a][b] = 2;
      return 2;
   }
}
   

inline void pisz(int n) {
   printf("%d\n",n);
}

int main () {
   FOR(i,31700) FOR(j,31) tab[i][j] = -1;
   
   tab[1][30] = 2;
   
   wez(a);
   wez(b);
   if (a == 1 && b >= 30) {
      printf("Missing");
      return 0;
   }
   scanf("%d",&n);
   tab[31697][1] = (n % 2 == 1);
   int ans = opt(a,b);
   if (ans == 1) printf("Masha");
   if (ans == 0) printf("Stas");
   if (ans == 2) printf("Missing");
//   printf(opt(a,b) ? "Masha" : "Stas");
}