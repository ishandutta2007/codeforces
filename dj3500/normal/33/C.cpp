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

int a[100006], m[100006], best[100006];

int main () {
   wez(n);
   FORI(i,n) scanf("%d",a+i);
   
   m[0] = 0;
   best[0] = 0;
   FORI(i,n) {
      m[i] = m[i-1] - a[i];
      best[i] = max(best[i-1] + a[i], m[i]);
   }
   
   int suma = 0;
   int maxx = best[n];
   for (int i = n; i >= 1; --i) {
      suma -= a[i];
      if (maxx < suma + best[i-1]) maxx = suma + best[i-1];
   }
   
   printf("%d\n",maxx);
}