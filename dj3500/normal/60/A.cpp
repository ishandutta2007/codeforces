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

int main () {
   wez(n)wez(m)
   int minn = 1, maxx = n;
   while(1) {
      string syf1,syf2,syf3,lr;
      int i;
      if (!(cin >> syf1)) break;
      cin >> syf2 >> lr >> syf3 >> i;
      if (lr=="left") maxx = min(maxx,i-1);
      if (lr=="right") minn = max(minn,i+1);
   }
   pisz((minn <= maxx) ? maxx-minn+1 : -1);
}