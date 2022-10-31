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

bool t[52][52];
int mini;

void go (int n, int m, int a, int b) {
   for (int i = 1; i <= n-a+1; ++i) {
      for (int j = 1; j <= m-b+1; ++j) {
         int val = 0;
         for (int ii = i; ii <= i+a-1; ++ii) {
            for (int jj = j; jj <= j+b-1; ++jj) {
               val += t[ii][jj];
            }
         }
         if (mini > val) mini = val;
      }
   }
}

int main () {
   wez(n);wez(m);
   FORI(i,n) {
      FORI(j,m) scanf("%d",&(t[i][j]));
   }
   wez(a);wez(b);
   
   mini = INF;
   if (a <= n && b <= m) go(n,m,a,b);
   if (a <= m && b <= n) go(n,m,b,a);
   pisz(mini);
   return 0;
}