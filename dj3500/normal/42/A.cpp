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

int a[101];
int b[101];

int main () {
   wez(n);wez(V);
   FOR(i,n) scanf("%d",a+i);
   FOR(i,n) scanf("%d",b+i);
   
   double mini = 100000;
   FOR(i,n) {
      double val = ((double)b[i])/((double)a[i]);
      if (val < mini) mini = val;
   }
   double sum = 0;
   FOR(i,n) {
      sum += mini * a[i];
   }
   double W = V;
   cout << min(W,sum) << endl;
}