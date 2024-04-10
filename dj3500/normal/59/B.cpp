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

int a[200];

int main () {
   wez(n)
   FOR(i,n) scanf("%d",a+i);
   int suma = 0;
   FOR(i,n) suma += a[i];
   if (suma % 2) pisz(suma);
   else {
      int min = INF;
      FOR(i,n) if (a[i] % 2) if (min > a[i]) min = a[i];
      if (min == INF) pisz(0);
      else pisz(suma-min);
   }
}