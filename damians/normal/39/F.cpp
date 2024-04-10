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
int frog[101], mosq[101];

int main () {
   wez(n);wez(m);wez(k);
   FORI(i,m) {
      wez(a);
      frog[i]=a;
   }
   FORI(i,k) {
      wez(a);
      mosq[i]=a;
   }
   int min = INF;
   vector<int> opt;
   FORI(i,m) {
      int kills = 0;
      FORI(j,k) {
         if (mosq[j] % frog[i] == 0) ++kills;
      }
      if (min == kills) {
         opt.pb(i);
      } else if (min > kills) {
         opt.clear();
         opt.pb(i);
         min = kills;
      }
   }
   pisz(opt.size());
   FOR(i,opt.size()) printf("%d ",opt[i]);     
}