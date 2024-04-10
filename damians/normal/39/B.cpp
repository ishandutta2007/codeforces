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
int x[102];

int main () {
   wez(n);
   FORI(i,n) {wez(a);x[i]=a;}
   vector<int> wynik;
   int k = 1, y = 1;
   while (y <= n) {
      if (x[y] == k) {
         wynik.pb(2000+y);
         k++;
      }
      y++;
   }
   if (wynik.empty()) {
      pisz(0);
   } else {
      pisz(wynik.size());
      FOR(i,wynik.size()) printf("%d ",wynik[i]);
   }
}