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

int main () {
   wez(l); wez(d); wez(v); wez(g); wez(r);
   double dv = (double)d/(double)v;
   double x = ((int)floor(dv) % (g+r)) + (dv - floor(dv));
//   double x = dv % (g+r);
   double wynik = ((double)l/(double)v);
   if (x >= g) wynik += ((double)r)+g-x;
   printf("%.9f\n",wynik);
}